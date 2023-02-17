let radius;
let checkRadius;

do {
    checkRadius = prompt("Введите радиус круга");
} while (!isFinite(Number(checkRadius)));

radius = Number(checkRadius);

// Function Declaration
function calcArea(x) {
    return Math.PI * x * x;
}

function calcDiameter(x) {
    return 2 * x;
}

function calcLength(x) {
    return 2 * Math.PI * x;
}

// Function Expression
const calcArea1 = function (x) {
    return Math.PI * x * x;
}

const calcDiameter1 = function (x) {
    return 2 * x;
}

const calcLength1 = function (x) {
    return 2 * Math.PI * x;
}

// Function Expression (arrow functions)
const calcArea2 = (x) => Math.PI * x * x;

const calcDiameter2 = (x) => 2 * x;

const calcLength2 = (x) => 2 * Math.PI * x;

console.log("Площадь круга(Function Declaration): " + calcArea(radius) + "\n" + 
"Площадь круга(Function Expression): " + calcArea1(radius) + "\n" +
"Площадь круга(Function Expression (arrow functions)): " + calcArea2(radius));

console.log("Диаметр круга(Function Declaration): " + calcDiameter(radius) + "\n" +
"Диаметр круга(Function Expression): " + calcDiameter1(radius) + "\n" +
"Диаметр круга(Function Expression (arrow functions)): " + calcDiameter2(radius));

console.log("Длина окружности(Function Declaration): " + calcLength(radius) + "\n" +
"Длина окружности(Function Expression): " + calcLength1(radius) + "\n" +
"Длина окружности(Function Expression (arrow functions)): " + calcLength2(radius));