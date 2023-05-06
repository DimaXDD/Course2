<%@ page import=" com.example.lab10.classes.DAO" %>
<%@ page import=" com.example.lab10.classes.Telegram" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="com.example.lab10.classes.Telegram" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
    <link rel="stylesheet" type="text/css" href="styles/welcome.css">
</head>
<body>

<jsp:include page="header.jsp"/>

<div id="container">
    <div id="tableDiv">
        <table>
            <thead>
            <tr>
                <th>ID</th>
                <th>Имя</th>
                <th>Категория</th>
                <th>Подпищики</th>
            </tr>
            </thead>

            <tbody>
            <%
                try {
                    DAO db = new DAO();
                    db.getConnection();

                    ArrayList<Telegram> classes = new ArrayList<>(db.getTelegram());
                    for (Telegram tch : classes)
                    {
            %>
            <tr>
                <td><%=tch.getId()%></td>
                <td><%=tch.getName()%></td>
                <td><%=tch.getCategory()%></td>
                <td><%=tch.getSubs()%></td>
            </tr>
            <%
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            %>
            </tbody>
        </table>
    </div>


    <div id="add-remove-div">
        <form id="add-form" method="POST" action="MainServlet">
            <h3 style="font-weight: bold">Добавить телеграмм-канал</h3>
            <input type="text" placeholder="Имя" name="name" autocomplete="off"/>
            <input type="text" placeholder="Категория" name="category" autocomplete="off"/>
            <input type="text" placeholder="Подпищики" name="subs" autocomplete="off"/>
            <button type="submit">Добавить</button>
        </form>
        <br/><br/>
        <form id="remove-form" method="GET" action="MainServlet">
            <h3 style="font-weight: bold">Удалить телеграмм-канал</h3>
            <input type="text" placeholder="ID" name="id" autocomplete="off"/>
            <button type="submit">Удалить</button>
        </form>
    </div>

</div>


<jsp:include page="footer.jsp"/>

</body>
</html>
