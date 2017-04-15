package com.vira.Calulateables;

import org.springframework.beans.factory.annotation.Autowired;

/**
 * GenericCalculation class is used as placeholder and a rather generic solution for calculations.
 *
 * Created by Vira on 15.04.2017.
 */
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
