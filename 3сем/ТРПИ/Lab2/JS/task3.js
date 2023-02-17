let textWithStudents;
let letter = "([A-Z]|[a-z]|[а-я]|[А-Я])";
let space = " ";
let word = `(${letter}+${space}*)+`
let reg = new RegExp(`(${word})+`);

do {
    textWithStudents = prompt("Введите имена студентов, которые присутствуют на паре, через запятую:");
} while (!textWithStudents.match(reg));

let studentList = textWithStudents.trim().split(",");
let count = studentList.length;

alert("Количество: " + count);