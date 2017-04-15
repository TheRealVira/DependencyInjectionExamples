package com.vira.Calulateables;

import java.util.stream.DoubleStream;

/**
 * Maximum class implements ICalculateable and simply returns the maximum value of all values passed as parameter.
 *
 * Created by Vira on 15.04.2017.
 */
public class Maximum implements ICalculateable {
    @Override
    public double calculate(double[] values) {
        return DoubleStream.of(values).max().getAsDouble();
    }

    @Override
    public String getDescription() {
        return "Calculates the highest number of all given values.";
    }
}
