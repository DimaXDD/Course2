let Notebook = {
  product_name: "notebook",
  amount: 250,
  price: 1500,
};

let Book = { 
    product_name: "book", 
    amount: 80, 
    price: 500
};

let Apple = { 
    product_name: "apple", 
    amount: 30,
    price: 10 
};

let basket = new Map([
  [1, Notebook],
  [2, Book],
  [3, Apple],
]);

// Добавление товара в корзину
function addProduct(name, count, price) { 
  return {
    product_name: name,
    amount: count,
    price: price,
  };
}

let choice = 1;

while (choice != 0) {
  choice = prompt(
    `1.Вывод товаров:\n2.Добавить товар\n3.Удалить товар\n4.Изменить количество товара\n5.Количество товаров и сумма заказа\n6.Выйти`
  );

  switch (choice) {
    case "1": {
      let arr = "";
      basket.forEach((value, key, map) => {
        arr = arr + "\nid: " + key + "\n";
        for (let inf in value) {
          arr = arr + inf + ": " + value[inf] + "\n";
        }
      });

      alert(`Ваши товары:\n` + arr);
      break;
    }

    case "2": {
      let name1 = prompt(
        "Введите название товара, который необходимо добавить: "
      );
      let count = prompt("Введите количество товара который нужно добавить: ");
      let mark = prompt("Введите цену товара, который нужно добавить: ");
      let idnew = prompt("Введите id товара, который нужно добавить: ");

      basket.forEach((key, map) => {
        let im = 0;
        while (im < basket.size) {
          if (idnew == key) {
            alert(`Нельзя добавить продукт с таким ID`);
            break;
          }
          im++;
        }
      });

      basket.set(idnew, addProduct(name1, count, mark));
      alert(`Товар добавлен!`);
      break;
    }

    case "3": {
      let IDdelete = prompt(`Введите ID товара, который необходимо удалить`);
      basket.delete(IDdelete);
      break;
    }

    case "4": {
      let idChange = prompt(
        `Введите ID товара, количество которого, вы собираетесь изменить`
      );
      let newCount = prompt(`Введите новое количество данного товара`);
      basket.get(+idChange).amount = newCount;
      break;
    }

    case "5": {
      let sumOfProduct = 0;
      basket.forEach((value, map) => {
        sumOfProduct += value.price;
      });

      alert(
        `Количество товаров: ${basket.size}\n` +
          `Сумма всх товаров: ${sumOfProduct}`
      );
      break;
    }

    case "6": {
      choice = 0;
      break;
    }
  }
}
