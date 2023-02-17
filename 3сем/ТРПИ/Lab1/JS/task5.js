let a_square = 5;
let a_rectangle = 45;
let b_rectangle = 21;

function getArea(x, y) {
    if (y === undefined) {
        return x * x;
    } else {
        return x * y;
    }
}

let first_result = getArea(a_square);
let second_result = getArea(a_rectangle, b_rectangle);

console.log(Math.floor(second_result / first_result));
