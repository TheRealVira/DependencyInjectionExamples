package com.vira;

import com.vira.Calulateables.GenericCalculation;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import java.io.*;
import java.net.URL;
import java.time.MonthDay;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

import org.w3c.dom.Document;

/**
 * Created by Vira on 15.04.2017.
 */
public class MainApp {

    /**
     *
     * @param args [0] if 0: load the local xml config file; if something else: load the online xml config file;
     * @throws Exception
     */
    public static void main(String[] args) throws Exception {
        // Loading an instance of the GenericCalculation
        // NOTE: We never actually call the constructor directly!
        ApplicationContext context =
                args[0].equals("0") ?
                        new ClassPathXmlApplicationContext("spring-config.xml"):
                        new ClassPathXmlApplicationContext(new String[]{DownloadNewest()}, true);
        GenericCalculation gc = (GenericCalculation) context.getBean("genCalc");

        // Some testing...
        System.out.println("Calculation testing:");
        System.out.println(gc.calculate(new double[]{1,2,3,4,5.3,-1}));
        System.out.println("===");
        System.out.println("Description:  " + gc.getDescription());
    }

    private static String DownloadNewest() throws Exception {
        final String ONLINE_CONFIG = "Java_example.xml";

        URL url = new URL("https://raw.githubusercontent.com/TheRealVira/DependencyInjectionExamples/master/Example%20XML%20Files/"+ONLINE_CONFIG);

        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document doc = db.parse(url.openStream());

        try(  PrintStream out = new PrintStream("out\\production\\Java_Example\\"+ONLINE_CONFIG )  ){
            printDocument(doc, out);
        }

        return ONLINE_CONFIG;
    }

    // thx to: http://stackoverflow.com/a/29643796
    public static void printDocument(Document doc, OutputStream out) throws IOException, TransformerException {
        TransformerFactory tf = TransformerFactory.newInstance();
        Transformer transformer = tf.newTransformer();
        transformer.setOutputProperty(OutputKeys.OMIT_XML_DECLARATION, "no");
        transformer.setOutputProperty(OutputKeys.METHOD, "xml");
        transformer.setOutputProperty(OutputKeys.INDENT, "yes");
        transformer.setOutputProperty(OutputKeys.ENCODING, "UTF-8");
        transformer.setOutputProperty("{http://xml.apache.org/xslt}indent-amount", "4");

        transformer.transform(new DOMSource(doc),
                new StreamResult(new OutputStreamWriter(out, "UTF-8")));
    }
}
