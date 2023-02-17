let mathMark = prompt("Введите оценку по математике");
let engMark = prompt("Введите оценку по английскому");
let rusMark = prompt("Введите оценку по русскому");

if (mathMark >= 4 && engMark >= 4 && rusMark >= 4) {
    alert("Вы прошли на следующий курс");
} else if (mathMark < 4 && engMark < 4 && rusMark < 4) {
    alert("Вас отчислят");
} else {
    alert("Вас ждёт пересдача");
}