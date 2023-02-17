// Задание 1

function createNumber(numberArr: number[]): string {
    if(numberArr.length != 10) return "Неверный формат номера";

    var phoneNum;

    phoneNum = String("(" + numberArr[0] + numberArr[1] + numberArr[2] + ") " + numberArr[3] + numberArr[4] + numberArr[5] + "-" + numberArr[6] + numberArr[7] + "-" + numberArr[8] + numberArr[9]);

    return phoneNum;
}

let num_arr: number[] = [3, 7, 5, 2, 9, 1, 2, 3, 4, 5];

console.log("Задание 1\n" + "Номер телефона после обработки: "+ createNumber(num_arr));

// Задание 2

class Challenge {
    static solution(number:number) : number
    {
        if(number < 0)
        {
            return 0;
        }

        else
        {
           let sum : number = 0;

            for(let i = 1; i < number; i++)
            {
                if(i % 3 == 0 || i % 5 == 0)
                {
                    sum += i;
                }
            }

            return sum;
        }
    }
}

console.log("Задание 2\n" + "Сумма /5 и /3: "+ Challenge.solution(10));

// Задание 3

function swapArray(arr:number[], k:number) : number[] | null
{
    if(k == null)
    {
        return arr;
    }

    if(k > arr.length){
        return null;
    }

    if(arr.length == 0)
    {
        return null;    
    }

    let newArr:number[] = [];

    for(let i = 0; i < k; i++)
    {
        newArr[i] = arr[arr.length - (k - i)];
    }

    for(let i = 0; i < arr.length - k; i++)
    {
        newArr[k + i] = arr[i];
    }

    return newArr;
}

console.log("Задание 3\n" + "Массив после обработки: "+ swapArray([1, 2, 3, 4, 5, 6, 7, 8, 9], 3));

// Задание 4

function GetMedian(arrnum1:number[], arrnum2:number[]) : number | null
{
    if(arrnum1.length == 0 && arrnum2.length == 0)
    {
        return null;
    }

    let concatTwoArr: number[] = []; // объединение двух массивов

    for(let i = 0; i < arrnum1.length; i++) // первый массив
    {
        concatTwoArr[i] = arrnum1[i];
    }

    let j: number = 0;

    for(let i = arrnum1.length; i < arrnum1.length + arrnum2.length; i++, j++) // второй массив
    {
        concatTwoArr[i] = arrnum2[j];
    }

    concatTwoArr.sort(); // сортировка массива (в примере массив отсортирован)

    if(concatTwoArr.length % 2 == 0)
    {
        return (concatTwoArr[(concatTwoArr.length / 2)-1] + concatTwoArr[concatTwoArr.length / 2])/2;
    }

    else
    {
        return concatTwoArr[Math.floor(concatTwoArr.length / 2)];
    }
}

console.log("Задание 4\n" + "Медиана: "+ GetMedian([1, 2], [3, 4]));
console.log("Медиана: "+ GetMedian([1, 3], [2]));

// Задание 5

function sudoku(matrix:number[][]) : string
{
    for(let i = 0; i < 9; i++)
    {
        for(let j = 0; j < 9; j++)
        {
            if(matrix[i][j] > 9 || matrix[i][j] < -1 || matrix[i][j] == 0)
            {
                return "Вышли за пределы";
            }
        }
    }

    for(let i = 0; i < 9; i++)
    {
        if(!RowChecking(matrix, i) || !ColChecking(matrix, i))
        {
            return "Доска неправильная";
        }
    }

    return "Доска правильная";
}

function RowChecking(matrix:number[][], k: number) : boolean
{
    let set = new Set<number>();

    for(let i = 0; i < 9; i++)
    {
        if(matrix[k][i] == null)
        {
            continue;
        }

        if(set.has(matrix[k][i]))
        {
            return false;
        }

        set.add(matrix[k][i]);
    }
    return true;
}

function ColChecking(matrix:number[][], k:number) : boolean
{
    let set = new Set<number>();

    for(let i = 0; i < 9; i++)
    {
        if(matrix[i][k] == null)
        {
            continue;
        }

        if(set.has(matrix[i][k]))
        {
            return false;
        }

        set.add(matrix[i][k]);
    }
    return true;
}

let sud: number[][] = [
    [5,3,null, null,7,null, null,null,null],
    [6,null,null, 1,9,5, null,null,null],
    [1,9,8, null,null,null, null,6,null],

    [8,null,null, null,6,null, null,null,3],
    [4,null,null, 8,null,3, null,null,1],
    [7,null,null, null,2,null, null,null,6],

    [null,6,null, null,null,null, 2,8,null],
    [null,null,null, 4,1,9, null,null,5],
    [null,null,null, null,8,null, null,7,9],
]

console.log("Задание 5\n" + "Результат: "+ sudoku(sud));