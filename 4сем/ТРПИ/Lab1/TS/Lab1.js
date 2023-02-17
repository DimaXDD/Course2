// Задание 1
function createNumber(numberArr) {
    if (numberArr.length != 10)
        return "Неверный формат номера";
    var phoneNum;
    phoneNum = String("(" + numberArr[0] + numberArr[1] + numberArr[2] + ") " + numberArr[3] + numberArr[4] + numberArr[5] + "-" + numberArr[6] + numberArr[7] + "-" + numberArr[8] + numberArr[9]);
    return phoneNum;
}
var num_arr = [3, 7, 5, 2, 9, 1, 2, 3, 4, 5];
console.log("Задание 1\n" + "Номер телефона после обработки: " + createNumber(num_arr));
// Задание 2
var Challenge = /** @class */ (function () {
    function Challenge() {
    }
    Challenge.solution = function (number) {
        if (number < 0) {
            return 0;
        }
        else {
            var sum = 0;
            for (var i = 1; i < number; i++) {
                if (i % 3 == 0 || i % 5 == 0) {
                    sum += i;
                }
            }
            return sum;
        }
    };
    return Challenge;
}());
console.log("Задание 2\n" + "Сумма /5 и /3: " + Challenge.solution(10));
// Задание 3
function swapArray(arr, k) {
    if (k == null) {
        return arr;
    }
    if (k > arr.length) {
        return null;
    }
    if (arr.length == 0) {
        return null;
    }
    var newArr = [];
    for (var i = 0; i < k; i++) {
        newArr[i] = arr[arr.length - (k - i)];
    }
    for (var i = 0; i < arr.length - k; i++) {
        newArr[k + i] = arr[i];
    }
    return newArr;
}
console.log("Задание 3\n" + "Массив после обработки: " + swapArray([1, 2, 3, 4, 5, 6, 7, 8, 9], 3));
// Задание 4
function GetMedian(arrnum1, arrnum2) {
    if (arrnum1.length == 0 && arrnum2.length == 0) {
        return null;
    }
    var concatTwoArr = []; // объединение двух массивов
    for (var i = 0; i < arrnum1.length; i++) // первый массив
     {
        concatTwoArr[i] = arrnum1[i];
    }
    var j = 0;
    for (var i = arrnum1.length; i < arrnum1.length + arrnum2.length; i++, j++) // второй массив
     {
        concatTwoArr[i] = arrnum2[j];
    }
    concatTwoArr.sort(); // сортировка массива (в примере массив отсортирован)
    if (concatTwoArr.length % 2 == 0) {
        return (concatTwoArr[(concatTwoArr.length / 2) - 1] + concatTwoArr[concatTwoArr.length / 2]) / 2;
    }
    else {
        return concatTwoArr[Math.floor(concatTwoArr.length / 2)];
    }
}
console.log("Задание 4\n" + "Медиана: " + GetMedian([1, 2], [3, 4]));
console.log("Медиана: " + GetMedian([1, 3], [2]));
// Задание 5
function sudoku(matrix) {
    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++) {
            if (matrix[i][j] > 9 || matrix[i][j] < -1 || matrix[i][j] == 0) {
                return "Вышли за пределы";
            }
        }
    }
    for (var i = 0; i < 9; i++) {
        if (!RowChecking(matrix, i) || !ColChecking(matrix, i)) {
            return "Доска неправильная";
        }
    }
    return "Доска правильная";
}
function RowChecking(matrix, k) {
    var set = new Set();
    for (var i = 0; i < 9; i++) {
        if (matrix[k][i] == null) {
            continue;
        }
        if (set.has(matrix[k][i])) {
            return false;
        }
        set.add(matrix[k][i]);
    }
    return true;
}
function ColChecking(matrix, k) {
    var set = new Set();
    for (var i = 0; i < 9; i++) {
        if (matrix[i][k] == null) {
            continue;
        }
        if (set.has(matrix[i][k])) {
            return false;
        }
        set.add(matrix[i][k]);
    }
    return true;
}
var sud = [
    [5, 3, null, null, 7, null, null, null, null],
    [6, null, null, 1, 9, 5, null, null, null],
    [1, 9, 8, null, null, null, null, 6, null],
    [8, null, null, null, 6, null, null, null, 3],
    [4, null, null, 8, null, 3, null, null, 1],
    [7, null, null, null, 2, null, null, null, 6],
    [null, 6, null, null, null, null, 2, 8, null],
    [null, null, null, 4, 1, 9, null, null, 5],
    [null, null, null, null, 8, null, null, 7, 9],
];
console.log("Задание 5\n" + "Результат: " + sudoku(sud));
