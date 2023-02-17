// Представьте фигуры на картинке в виде объектов. 

const firstCube = {
    width: '250px',
    height: '250px',
    border: '5px solid black',
    background: 'yellow'
}

const firstCircle = {
    width: '250px',
    height: '250px',
    border: '5px solid black',
    borderRadius : '50%',
    background: 'white'
}

const firstTriangle = {
    width: 0,
    height: 0,
    borderColor: 'transparent transparent #fff transparent',
    borderWidth: '0 30px 30px 30px',
    middleLine: true,
}

const secondCube = {
    width: '100px',
    height: '100px',
    border: '5px solid black',
    background: 'yellow'
}

const secondCircle = {
    width: '100px',
    height: '100px',
    border: '5px solid black',
    borderRadius : '50%',
    background: 'green'
}

const secondTriangle = {
    width: 0,
    height: 0,
    borderColor: 'transparent transparent #fff transparent',
    borderWidth: '0 30px 30px 30px',
    threeMiddleLines: true,
}


// Свойства, которые отличают фигуру «зеленый круг»
function CircleDifference(figureOne, figureTwo) {
    const propsOne = Object.getOwnPropertyNames(figureOne); // получаем массив свойств
    const propsTwo = Object.getOwnPropertyNames(figureTwo); // получаем массив свойств

    for(let counter = 0; counter < propsOne.length; counter++){
        if(figureOne[propsOne[counter]] != figureTwo[propsTwo[counter]]){
            console.log(propsOne[counter] + ' : ' + figureOne[propsOne[counter]] + ' - ' + figureTwo[propsTwo[counter]]);
        }
    }
}
console.log('Различия между двумя кругами:');
CircleDifference(secondCircle, firstCircle);

// Свойства, которые описывают фигуру «треугольник с тремя линиями»
function Triangle(figureOne) {
    const propsOne = Object.getOwnPropertyNames(figureOne); // получаем массив свойств

    for(let counter = 0; counter < propsOne.length; counter++){
        console.log(propsOne[counter] + ' : ' + figureOne[propsOne[counter]]);
    }
}
console.log('Свойства треугольника с тремя линиями:');
Triangle(secondTriangle);

// Есть ли у фигуры «маленький квадрат» собственное свойство, которое определяет цвет фигуры
function OwnColor(figureOne, figureTwo){
    const propsOne = Object.getOwnPropertyNames(figureOne);
    const propsTwo = Object.getOwnPropertyNames(figureTwo);
    let state = 0;
    for(let counter = 0; counter < propsOne.length; counter++){
        if(figureOne[propsOne[counter]] == 'yellow'){
            for(let x = 0; x < propsOne.length; x++){
                if(propsOne[counter] == propsTwo[x]){
                    console.log('Цветовое свойство куба не уникально');
                    state++;
                    break;
                }
            }
        }
    }
    
    if(state == 0){
        console.log('Цветовое свойство куба уникально');
    }
}
console.log('Цветовое свойство куба:');
OwnColor(firstCube, secondCube);


