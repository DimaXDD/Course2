let first_parm;
let second_parm;
let third_parm;
let isAgree = false;

first_parm = prompt("Введите первый параметр: ");

if (first_parm) {
  second_parm = prompt("Введите второй параметр: ");
  isAgree = confirm("Вы хотите ввести третий параметр?");

  if (isAgree) {
    third_parm = prompt("Введите третий параметр: ");
    console.log(toString(first_parm, second_parm, third_parm));
    console.log(typeof toString(first_parm, second_parm, third_parm));
  } else {
    console.log(toString(first_parm, second_parm));
    console.log(typeof toString(first_parm, second_parm));
  }
} else {
  second_parm = prompt("Введите второй параметр: ");

  isAgree = confirm("Вы хотите ввести третий параметр?");

  if (isAgree) {
    third_parm = prompt("Введите третий параметр: ");
    console.log(toString(undefined, second_parm, third_parm));
    console.log(typeof toString(undefined, second_parm, third_parm));
  } else {
    console.log(toString(undefined, second_parm));
    console.log(typeof toString(undefined, second_parm));
  }
}

function toString(first_parm = 1, second_parm, third_parm) {
  return `${first_parm} ${second_parm} ${third_parm}`;
}
