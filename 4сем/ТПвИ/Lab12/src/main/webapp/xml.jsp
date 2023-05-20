<%--
  Created by IntelliJ IDEA.
  User: dimat
  Date: 20.05.2023
  Time: 1:11
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@ taglib prefix = "x" uri = "http://java.sun.com/jsp/jstl/xml"%>
<html>
<head>
    <title>JSTL XML</title>
    <link rel="stylesheet" href="style/sql.css">
</head>
<body>
    <c:import var = "productsInfo" url = "products.xml" charEncoding="UTF-8"/>
    <x:parse xml = "${productsInfo}" var = "output"/>

    <table>
        <tr>
            <th>Название</th>
            <th>Артикул</th>
            <th>Категория</th>
            <th>Бренд</th>
            <th>Цена</th>
            <th>Количество</th>
        </tr>
        <x:forEach select="$output/products_list/product" var="item">
            <tr>
                <td><x:out select="$item/name"/></td>
                <td><x:out select="$item/item_number"/></td>
                <td><x:out select="$item/category"/></td>
                <td><x:out select="$item/brand"/></td>
                <td><x:out select="$item/price"/></td>
                <td><x:out select="$item/quantity"/></td>
            </tr>
        </x:forEach>
    </table>

    <h4>---- url ----</h4>
    <a href="<c:url value="index.jsp"/>">На главную</a>

</body>
</html>
