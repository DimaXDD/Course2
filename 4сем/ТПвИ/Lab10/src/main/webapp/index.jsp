<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>JSP - Hello World</title>
</head>
<body>
<div style="width: 100%;height: 100%; display: flex;justify-content: center">
    <form  style="width: 400px">
        <h2 style="background: blue">Authorization</h2>
        <input type="text" value="" style="display: block;width: 400px" name="login"/>
        <input type="text" value="" style="display: block; width: 400px; margin-top: 10px" name="password"/>
        <div style="display: flex;justify-content: center">
            <input  type="submit" formaction="HelloServlet" formmethod="get" value="Auto" style="display: block; margin:10px 10px 10px 0px"/>
            <input type="submit" formaction="RegisterServ" formmethod="get" value="Reg" style="display: block; margin:10px 10px 10px 0px"/>
        </div>
    </form>
</div>
</body>
</html>