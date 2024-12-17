// function showElement() {
//     var element = document.getElementById("myElement");
//     element.style.display = "block";
// }
// Получаем ссылки на кнопку и элемент, который нужно скрывать/показывать
const toggleButton = document.getElementById("toggleButton");
const elementToToggle = document.getElementById("elementToToggle");

// Флаг для отслеживания состояния элемента (скрыт или показан)
let isElementHidden = false;

// Добавляем обработчик события клика на кнопку
toggleButton.addEventListener("click", function () {
  // Проверяем текущее состояние элемента
  if (isElementHidden) {
    // Если элемент скрыт, показываем его
    elementToToggle.style.display = "block";
    isElementHidden = false;
  } else {
    // Если элемент видим, скрываем его
    elementToToggle.style.display = "none";
    isElementHidden = true;
  }
});