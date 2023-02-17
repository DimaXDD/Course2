var products = new Set(["Линейка", "Апельсин", "Тетрадь"]);

let choice = 1;

while (choice != 0) {
  choice = prompt(
    `1 - добавить элемент в список\n2 - удалить элемент из списка\n3 - проверить наличие товара` +
      `\n4 - количество товаров в списке\n5 - вывод всего списка\n6 - выход`
  );

  switch (choice) {
    case "1": {
      const productNew = prompt("Введите товар, который надо добавить: ");
      products.add(productNew);
      alert(`Товар добален!`);
      break;
    }

    case "2": {
      const productDel = prompt("Введите товар, который надо добавить: ");
      products.delete(productDel);
      alert(`Товар удалён!`);
      break;
    }
    case "3": {
      const productHas = prompt(
        "Введите товар, который надо проверить на наличие: "
      );

      if (products.has(productHas) == true) { // по значению
        alert(`Продукт ${productHas} есть!`);
      } else {
        alert(`Продукт ${productHas} отсутствует!`);
      }
      break;
    }

    case "4": {
      alert("Количество товаров: " + products.size);
      break;
    }

    case "5": {
      let arr = "";
      for (let product of products) {
        arr += product + " ";
      }
      alert(`Ваши товары:\n` + arr);
      break;
    }
    case "6": {
      choice = 0;
      break;
    }
  }
}
