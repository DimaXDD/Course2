package com.example.lab12;

import jakarta.servlet.jsp.JspException;
import jakarta.servlet.jsp.JspWriter;
import jakarta.servlet.jsp.tagext.TagSupport;

import java.io.IOException;
import java.sql.ResultSet;
import java.sql.SQLException;

public class TDSprintTable extends TagSupport {
    private static final DAO db = new DAO();
    private String nameTable;
    public void setNameTable(String nameTable) {
        this.nameTable = nameTable;
    }
    @Override
    public int doStartTag() throws JspException {
        try {
            JspWriter out = pageContext.getOut();
            out.write("<h1>" + nameTable + "</h1>");
            out.write("<table border='1' style='border-spacing:0'>");
            out.write("<tr>");
        } catch (IOException e) {
            throw new JspException(e.getMessage());
        }
        db.getConnection();

        ResultSet rs = db.ExecuteQuery("SELECT COUNT(*)[count]\n" +
                " FROM INFORMATION_SCHEMA.COLUMNS\n" +
                " WHERE table_catalog = 'Lab9_Java'\n" +
                " AND table_name = '" + nameTable +"'");
        int columns_count = 0;
        while (true) {
            try {
                if (!rs.next()) break;
                columns_count = rs.getInt("count");
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
        if (columns_count != 0) {
            ResultSet rows = db.ExecuteQuery("select * from " + nameTable);
            try {
                while (rows.next()) {
                    for (int j = 0; j < columns_count; j++) {
                        pageContext.getOut().write("<td>");
                        pageContext.getOut().write(rows.getString(j + 1));
                        pageContext.getOut().write("</td>");
                    }
                    pageContext.getOut().write("</tr><tr>");
                }
            } catch (IOException e) {
                throw new JspException(e.getMessage());
            }
            catch (SQLException e) {
                throw new RuntimeException(e);
            }
            return EVAL_BODY_AGAIN;
        }
        else
            return SKIP_BODY;
    }

    @Override
    public int doEndTag() throws JspException {
        JspWriter out = pageContext.getOut();
        try {
            out.write("</tr>");
            out.write("</table>");
        } catch (IOException e) {
            throw new JspException(e.getMessage());
        }
        return EVAL_PAGE;
    }
}
