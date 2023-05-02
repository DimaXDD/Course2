<%--
  Created by IntelliJ IDEA.
  User: dimat
  Date: 01.05.2023
  Time: 1:43
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<div>
    <h3>User login: ${login}</h3>
    <h3>User password: ${password}</h3>
</div>
<div style="margin-top: 100px;display: block;horiz-align: center;vertical-align: center;width: 600px;background: ivory;">
    <li style="display: flex;justify-content: space-between; align-items: center; align-content: center;width: 600px;border: black 2px solid">
        <p style="display: inline; margin: 30px 0px 30px 0px; background: antiquewhite;width: 120px;font-size: 32px" >ID</p>
        <p style="display: inline; margin: 30px 0px 30px 0px; background: antiquewhite;width: 120px;font-size: 32px">Name</p>
        <p style="display: inline; margin: 30px 0px 30px 0px; background: antiquewhite;width: 120px;font-size: 32px">Type</p>
    </li>
    <c:forEach var="item" items="${planes}">
        <li style="display: flex;justify-content: space-between; align-items: center; align-content: center;width: 600px">
            <p style="display: inline; margin: 30px 0px 30px 0px; background: antiquewhite;width: 120px;font-size: 32px" ><c:out value="${item.getId()}"/></p>
            <p style="display: inline; margin: 30px 0px 30px 0px; background: antiquewhite;width: 120px;font-size: 32px"><c:out value="${item.getName()}"/></p>
            <p style="display: inline; margin: 30px 0px 30px 0px; background: antiquewhite;width: 120px;font-size: 32px"><c:out value="${item.getType()}"/></p>
        </li>
    </c:forEach>
</div>

<div style="margin-top: 100px;display: flex;justify-content: space-between">
    <div style="display: flex">
        <form>
            <h3>Insert</h3>
            <h4>Enter id</h4>
            <input type="text" value="" style="display: block;width: 400px" name="id"/>
            <h4>Enter type</h4>
            <input type="text" value="" style="display: block; width: 400px; margin-top: 10px" name="type"/>
            <h4>Enter name</h4>
            <input type="text" value="" style="display: block; width: 400px; margin-top: 10px" name="name"/>
            <input type="submit" formaction="InsertServlet" formmethod="get" value="insert" style="display: block; margin:10px 10px 10px 0px"/>
        </form>
    </div>
    <div style="display: flex">
        <form>
            <h3>Delete</h3>
            <h4>Enter id</h4>
            <input type="text" value="" style="display: block; width: 100px;height: 50px" name="id"/>
            <input type="submit" formaction="Delete" formmethod="get" value="delete" style="display: block; margin:10px 10px 10px 0px;height: 50px"/>
        </form>
    </div>
</div>

</body>
</html>

