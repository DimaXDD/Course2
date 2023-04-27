<%--
  Created by IntelliJ IDEA.
  User: dimat
  Date: 28.04.2023
  Time: 1:56
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java"
         xmlns:c="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>Admin page</title>
    <link href="mainPageTableStyle_10.css" rel="stylesheet" type="text/css">
</head>
<body>

<jsp:include page="header_10.jsp"/>

<div id="container">
    <div id="tableDiv">
        <table>
            <thead>
            <tr>
                <th>Логин</th>
                <th>Пароль</th>
                <th>Роль</th>
            </tr>
            </thead>

            <tbody>
            <c:forEach step="1" varStatus="loopCounter" items="${usersList}" var="user">
                <tr>
                    <td>
                        <c:out value="${user.getUserName()}" />
                    </td>
                    <td>
                        <c:out value="${user.getUserPassword()}" />
                    </td>
                    <td>
                        <c:out value="${user.getUserRole()}" />
                    </td>
                </tr>
            </c:forEach>
            </tbody>
        </table>
    </div>


    <div id="add-remove-div">
        <form id="add-form" method="post" action="main-admin-servlet">
            <h3 style="font-weight: bold">Добавить пользователя</h3>
            <input type="text" placeholder="Логин" name="login" autocomplete="off"/>
            <input type="text" placeholder="Пароль" name="password" autocomplete="off"/>
            <input type="text" placeholder="Роль" name="role" autocomplete="off"/>
            <button type="submit">Добавить</button>
        </form>
        <br/><br/>
        <form id="remove-form" method="get" action="main-admin-servlet">
            <h3 style="font-weight: bold">Удалить пользователя</h3>
            <input type="text" placeholder="Логин" name="login" autocomplete="off"/>
            <button type="submit">Удалить</button>
        </form>
    </div>

</div>


<jsp:include page="footer_10.jsp"/>

</body>
</html>
