## Short summary
This example explains how to use dependency injections **local** and **online**!

## Task
The customer wants a software solution, which allows the following things:
* An documented generic interface to make mathematical calulations.
* A way to change the method of calculating, **without** "recompiling" the program.
* A method to load the configuration file (which holds the selection of how the customer wants to calculate) online and ofline/local online.
* That configuration file has to be handled using _``*.xml``_ format using the [Spring Framework](https://projects.spring.io/spring-framework/)

## How to use it
This project is based on the **``ICalculateable``**, which holds a ``calculate(double[] values)`` and a ``getDescription()`` method. To use it, simple implement it:

````
public class Addition implements ICalculateable {
    @Override
    public double calculate(double[] values) {
        return DoubleStream.of(values).sum();
    }

    @Override
    public String getDescription() {
        return "Sums up all values.";
    }
}
````

## Spring bean file
The bean file could look like the following example:

````
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:context="http://www.springframework.org/schema/context"
       xsi:schemaLocation="http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd http://www.springframework.org/schema/context http://www.springframework.org/schema/context/spring-context.xsd">

    <context:component-scan base-package="com.vira.Calulateables" />

    <!-- Calculateables -->
    <bean id="addition" class="com.vira.Calulateables.Addition" />
    <bean id="maximum" class="com.vira.Calulateables.Maximum" />

    <!-- Defining our generic calculator, which may use an other ICalculateable in the future. -->
    <bean id="genCalc" class="com.vira.Calulateables.GenericCalculation">
        <!-- For now I want it to use the maximum calculation. -->
        <constructor-arg ref="maximum"/>
    </bean>
</beans>
````
### Keys
* ``<!-- Calculateables -->`` both (``addition`` and ``maximum``) do implement the ``ICalculateable`` interface and have to be defined inside our bean file, so we are able to autowire them to our generic ``GenericCalculation``.
* ``genCalc`` defines our ``GenericCalculation`` which will get an instance of our ``maximum`` ``ICalculateable``, which we have defined aboth.

### How to load the instance of ``GenericCalculation`` (holding the id ``"genCalc"``) from the bean file
````
ApplicationContext context = new ClassPathXmlApplicationContext("spring-config.xml");
GenericCalculation gc = (GenericCalculation) context.getBean("genCalc");
````
### Note
We do not actually directly call the constructor of ``GenericCalculation``!

### ``GenericCalculation``
````
public class GenericCalculation {
    private ICalculateable _calculateable;

    @Autowired
    public GenericCalculation(ICalculateable calulateable){
        this._calculateable = calulateable;
    }

    public double calculate(double[] values) {
        return _calculateable.calculate(values);
    }

    public String getDescription() {
        return _calculateable.getDescription();
    }
}
````
The **``@Autowired``** attribute tells the spring framework to automatically pass over the correct parameters (which we have defined inside our bean file).
