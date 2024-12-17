var W3CDOM = (document.getElementsByTagName && document.createElement);

 window.onload = initialize; 

function initialize () {

	if (W3CDOM)
	
	{
      //Регистрация события onclick по модели W3C
		var x = document.getElementById("ex");
      x.addEventListener("click",showPopup,false);
		
      //Регистрация события onclick по традиционной модели 
		var t = document.getElementById("ex1");
		t.onclick = showPopup;
   } 
}
 
 //Переключатель видимости
 function toggle(targetId)
  {
    if (document.getElementById)
	  {
	    target = document.getElementById(targetId);
		 if (target.style.display == "none")
		  {
		    target.style.display = "";
		  } else
		  {
		    target.style.display = "none";
		  }
	  }
  }

function showPopup()
{
  alert("Великолепно!")
  var popup = window.open("node.html", "popup", "height=600,width=600");
  popup.focus();
  return false;
}
 

// Timezone stuff
// tz in format [+-]HHMM
function checkTimezone( tz, msg ) {
	var localclock = new Date();
	// returns negative offset from GMT in minutes
	var tzRaw = localclock.getTimezoneOffset();
	var tzHour = Math.floor( Math.abs(tzRaw) / 60);
	var tzMin = Math.abs(tzRaw) % 60;
	var tzString = ((tzRaw >= 0) ? "-" : "+") + ((tzHour < 10) ? "0" : "") + tzHour + ((tzMin < 10) ? "0" : "") + tzMin;
	if( tz != tzString ) {
		var junk = msg.split( '$1' );
		document.write( junk[0] + "UTC" + tzString + junk[1] );
	}
}
function unhidetzbutton() {
    tzb = document.getElementById('guesstimezonebutton')
    if(tzb) tzb.style.display = 'inline';
}

// in [-]HH:MM format...
// won't yet work with non-even tzs
function fetchTimezone() {
	// FIXME: work around Safari bug
	var localclock = new Date();
	// returns negative offset from GMT in minutes
	var tzRaw = localclock.getTimezoneOffset();
	var tzHour = Math.floor( Math.abs(tzRaw) / 60);
	var tzMin = Math.abs(tzRaw) % 60;
	var tzString = ((tzRaw >= 0) ? "-" : "") + ((tzHour < 10) ? "0" : "") + tzHour +
		":" + ((tzMin < 10) ? "0" : "") + tzMin;
	return tzString;
}

function guessTimezone(box) {
	document.preferences.wpHourDiff.value = fetchTimezone();
}

function showTocToggle(show,hide) {
	if(document.getElementById) {
		document.writeln('<span class=\'toctoggle\'>[<a href="javascript:toggleToc()">' +
		'<span id="showlink" style="display:none">' + show + '</span>' +
		'<span id="hidelink">' + hide + '</span>'
		+ '</a>]</span>');
	}
}


function toggleToc() {
	var toc = document.getElementById('tocinside');
	var showlink=document.getElementById('showlink');
	var hidelink=document.getElementById('hidelink');
	if(toc.style.display == 'none') {
		toc.style.display = tocWas;
		hidelink.style.display='';
		showlink.style.display='none';

	} else {
		tocWas = toc.style.display;
		toc.style.display = 'none';
		hidelink.style.display='none';
		showlink.style.display='';

	}
}
