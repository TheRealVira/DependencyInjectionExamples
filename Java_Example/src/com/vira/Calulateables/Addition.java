package com.vira.Calulateables;

import java.util.stream.DoubleStream;

/**
 * Addition class implements ICalculateable and simply returns the sum of all values passed as parameter.
 *
 * Created by Vira on 15.04.2017.
 */
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
