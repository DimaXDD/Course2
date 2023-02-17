//#region Ввод катетов
let firstCheck;
do {
  firstCheck = prompt("Введите длину первого катета AB");
} while (!isFinite(Number(firstCheck)));

let firstСathetus = Number(firstCheck);

let secondCheck;
do {
  secondCheck = prompt("Введите длину второго катета BC");
} while (!isFinite(Number(secondCheck)));

let secondСathetus = Number(secondCheck);
//#endregion


//#region Функции
function getHypotenuse(a, b) {
  return Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2));
}

function getArea(a, b) {
  return a * b / 2;
}

function getPerimeter(a, b) {
  return a + b + getHypotenuse(a, b);
}

function getHeight(a, b) {
    return (a * b) / getHypotenuse(a, b);
}

function getCosA(a, b) {
    return (a / getHypotenuse(a, b)).toFixed(2);
}

function getCosB(a, b) {
    return (b / getHypotenuse(a, b)).toFixed(2);
}

function getSinA(a, b) {
    return (b / getHypotenuse(a, b)).toFixed(2);
}

function getSinB(a, b) {
    return (a / getHypotenuse(a, b)).toFixed(2);
}

function getTanA(a, b) {
    return (b / a).toFixed(2);
}

function getTanB(a, b) {
    return (a / b).toFixed(2);
}

function getAtanA(a, b) {
    return (a / b).toFixed(2);
}

function getAtanB(a, b) {
    return (b / a).toFixed(2);
}
//#endregion

alert(`Гипотенуза: ${getHypotenuse(firstСathetus, secondСathetus)}
Площадь: ${getArea(firstСathetus, secondСathetus)}
Периметр: ${getPerimeter(firstСathetus, secondСathetus)}
Высота: ${getHeight(firstСathetus, secondСathetus)}
Косинус угла A: ${getCosA(firstСathetus, secondСathetus)}
Косинус угла B: ${getCosB(firstСathetus, secondСathetus)}
Синус угла A: ${getSinA(firstСathetus, secondСathetus)}
Синус угла B: ${getSinB(firstСathetus, secondСathetus)}
Тангенс угла A: ${getTanA(firstСathetus, secondСathetus)}
Тангенс угла B: ${getTanB(firstСathetus, secondСathetus)}
Арктангенс угла A: ${getAtanA(firstСathetus, secondСathetus)}
Арктангенс угла B: ${getAtanB(firstСathetus, secondСathetus)}`);
