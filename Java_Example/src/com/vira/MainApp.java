package com.vira;

import com.vira.Calulateables.GenericCalculation;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import java.net.URL;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;

/**
 * Created by Vira on 15.04.2017.
 */
public class MainApp {
    public static void main(String[] args) throws Exception {
        // Loading an instance of the GenericCalculation
        // NOTE: We never actually call the constructor directly!

        ApplicationContext context =
                args[0].equals("0") ?
                        new ClassPathXmlApplicationContext("spring-config.xml"):
                        new ClassPathXmlApplicationContext(DownloadNewest());
        GenericCalculation gc = (GenericCalculation) context.getBean("genCalc");

        // Some testing...
        System.out.println("Calculation testing:");
        System.out.println(gc.calculate(new double[]{1,2,3,4,5.3,-1}));
        System.out.println("===");
        System.out.println("Description:  " + gc.getDescription());
    }

    private static String DownloadNewest() throws Exception {
        final String ONLINE_CONFIG = "o-spring-config.xml";
        Document doc = loadTestDocument("https://raw.githubusercontent.com/TheRealVira/DependencyInjectionExamples/master/Java_Example/"+ONLINE_CONFIG);
        System.out.println(doc);
        return ONLINE_CONFIG;
    }

    private static Document loadTestDocument(String url) throws Exception {
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        factory.setNamespaceAware(true);
        return factory.newDocumentBuilder().parse(new URL(url).openStream());
    }
}
