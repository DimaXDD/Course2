package by.trubach.xmlparser;

import javax.xml.stream.*;
import javax.xml.stream.events.XMLEvent;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;


public class StaxStreamProcessor implements AutoCloseable
{
    private static final XMLInputFactory FACTORY = XMLInputFactory.newInstance();

    // объект парсера XML
    private final XMLStreamReader reader;

    public XMLStreamReader getReader() {
        return reader;
    }


    // запустить stream
    public StaxStreamProcessor(InputStream is) throws XMLStreamException
    {
        reader = FACTORY.createXMLStreamReader(is);
    }

    // закрыть поток
    @Override
    public void close()
    {
        if (reader != null)
        {
            try
            {
                reader.close();
            }
            catch (XMLStreamException e) { }
        }
    }


    // код поиска нужного события
    public boolean doUntil(int stopEvent, String value) throws XMLStreamException
    {
        while (reader.hasNext())
        {
            int event = reader.next();
            if (event == stopEvent && value.equals(reader.getLocalName()))
                return true;
        }
        return false;
    }


    // сканирует XML либо до конца тэга родителя, либо до заданного элемента
    public boolean startElement(String element, String parent) throws XMLStreamException
    {
        while (reader.hasNext())
        {
            int event = reader.next();

            if (parent != null && event == XMLEvent.END_ELEMENT && parent.equals(reader.getLocalName()))
                return false;

            if (event == XMLEvent.START_ELEMENT && element.equals(reader.getLocalName()))
                return true;
        }
        return false;
    }


    // чтение атрибута
    public String getAttribute(String name) throws XMLStreamException
    {
        return reader.getAttributeValue(null, name);
    }


    // чтение текста
    public String getText() throws XMLStreamException
    {
        return reader.getElementText();
    }

    /**
     * удобная функция для добавления объектов в список
     * @param element — тег XML-файла, который необходимо считать (например, Name)
     * @param list — список из мейна, в который надо поместить массив данных из этого тега (напр. listNames)
     */
    public static void addNamesToList(String element, ArrayList<String> list)
    {
        try (StaxStreamProcessor processor = new StaxStreamProcessor(Files.newInputStream(Paths.get("files/taxilist.xml")))) {
            XMLStreamReader reader = processor.getReader();
            while (processor.startElement(element, "TaxiList"))
                list.add(processor.getText());
        }
        catch (XMLStreamException | IOException e) {
            e.printStackTrace();
        }
    }
}
