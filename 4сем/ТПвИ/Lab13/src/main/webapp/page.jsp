
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<html>
<head>
    <title>Основная страница</title>
    <link rel="stylesheet" type="text/css" href="styles/page.css">
</head>
<body>
<div class="container">
    <div1>
        <jsp:include page="header.jsp"/>
        <c:catch var="Exception">
            <c:set var="currentUser" value="${user}" scope="page"/>
            <c:if test="${not empty currentUser and currentUser eq 'user'}">
                you are user
            </c:if>
        </c:catch>
        <br/>
    </div1>
</div>
<form>
    <a href="register.jsp">Регистрация</a>
    <a href="welcome.jsp">Авторизация</a>
</form>
<center>
    <div1 >
        <h3 style="color: red">${error}</h3>
        <table border="2" cellpadding="4">
            <tr>
                <th>Название</th>
                <th>Категория</th>
                <th>Подписчики</th>
            </tr>
            <c:forEach items="${telegrams}" var="telegram">
                <tr>
                    <td>${telegram.name}</td>
                    <td>${telegram.category}</td>
                    <td>${telegram.subs}</td>
                </tr>
            </c:forEach>
        </table>
    </div1>
    <fieldset>
        <legend>add</legend>
        <form action="${pageContext.request.contextPath}/controller?command=addTelegram" method="post"   >
            <h3>Название канала:</h3>
            <input type="text" name="name"/>
            <h3>Категория:</h3>
            <input type="text" name="country"/>
            <h3>Подписчики</h3>
            <input type="text" name="subs"/>
            <br/><br/>
            <input type="submit" value="Добавить" ><br/>
        </form>
    </fieldset>
    <fieldset>
        <legend>delete</legend>
        <form action="${pageContext.request.contextPath}/controller?command=delTelegram" method="post" >
            <h3>Удалить по названию:</h3>
            <input type="text" name="namedelet"/>
            <input type="submit" value="Удалить" ><br/>
        </form>
    </fieldset>

    <fieldset>
        <legend>update</legend>
        <form action="${pageContext.request.contextPath}/controller?command=updTelegram" method="POST">
            <h3>Название:</h3>
            <input name="name" type="text"/> <br/>
            <h3>Изменить кол-во:</h3>
            <input name="number" type="text" />
            <br/><br/>
            <input type="submit" value="Update"/>
        </form>
    </fieldset>
</center>
<jsp:include page="footer.jsp" />
</body>
</html>