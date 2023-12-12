/*
 * File: main.c
 * Creator: George Ferguson
 * Created: Mon Nov 28 14:11:17 2016
 */
#include <stdio.h>
#include <stdlib.h>
#include "Circuit.h"

static Circuit and3_Circuit(void) {

    char *title = "Two AND gates connected to make a 3-input AND circuit";

    // Create the inputs
    int NINPUTS = 3;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean z = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;
    inputs[2] = z;

    // Create the outputs
    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the gates
    int NGATES = 2;
    Gate A1 = new_AndGate();
    Gate A2 = new_AndGate();
    Gate* gates = new_Gate_array(NGATES);
    gates[0] = A1;
    gates[1] = A2;

    // Create the circuit
    Circuit circuit = new_Circuit(title,
				  NINPUTS, inputs,
				  NOUTPUTS, outputs,
				  NGATES, gates);

    // Connect the gates in the circuit
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A1, 1));
    Boolean x_and_y = Gate_getOutput(A1);

    Circuit_connect(circuit, x_and_y, Gate_getInput(A2, 0));
    Circuit_connect(circuit, z, Gate_getInput(A2, 1));
    Boolean x_and_y_and_z = Gate_getOutput(A2);

    Circuit_connect(circuit, x_and_y_and_z, result);

    // Done!
    return circuit;
}

static Circuit partA_circuit(void) {
    char *title = "Circuit for Part A";

    // Create the inputs
    int NINPUTS = 2;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;

    // Create the output
    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the gates
    int NGATES = 4;
    Gate A1 = new_AndGate();
    Gate A2 = new_OrGate();
    Gate A3 = new_Inverter();
    Gate A4 = new_AndGate();
    Gate* gates = new_Gate_array(NGATES);
    gates[0] = A1;
    gates[1] = A2;
    gates[2] = A3;
    gates[3] = A4;

    // Create the circuit
    Circuit circuit = new_Circuit(title,
                                  NINPUTS, inputs,
                                  NOUTPUTS, outputs,
                                  NGATES, gates);

    // Connect the gates in the circuit
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A1, 1));
    Boolean x_and_y = Gate_getOutput(A1);

    Circuit_connect(circuit, x, Gate_getInput(A2, 0));
    Circuit_connect(circuit, y, Gate_getInput(A2, 1));
    Boolean x_or_y = Gate_getOutput(A2);

    Circuit_connect(circuit, x_and_y, Gate_getInput(A3, 0));
    Boolean not_x_and_y = Gate_getOutput(A3);

    Circuit_connect(circuit, not_x_and_y, Gate_getInput(A4, 0));
    Circuit_connect(circuit, x_or_y, Gate_getInput(A4, 1));
    Boolean final = Gate_getOutput(A4);
    Circuit_connect(circuit, final, result);

    // Done!
    return circuit;
}

static Circuit partB_circuit(void) {
    char *title = "Circuit for Part B";

    // Create the inputs
    int NINPUTS = 2;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;

    // Create the output
    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the gates
    int NGATES = 6;
    Gate A1 = new_OrGate();
    Gate A2 = new_Inverter();
    Gate A3 = new_OrGate();
    Gate A4 = new_Inverter();
    Gate A5 = new_OrGate();
    Gate A6 = new_Inverter();
    Gate* gates = new_Gate_array(NGATES);
    gates[0] = A1;
    gates[1] = A2;
    gates[2] = A3;
    gates[3] = A4;
    gates[4] = A5;
    gates[5] = A6;

    // Create the circuit
    Circuit circuit = new_Circuit(title,
                                  NINPUTS, inputs,
                                  NOUTPUTS, outputs,
                                  NGATES, gates);
    // Connect the gates in the circuit
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A1, 1));
    Boolean x_or_y_1 = Gate_getOutput(A1);
    Circuit_connect(circuit, x, Gate_getInput(A3, 0));
    Circuit_connect(circuit, y, Gate_getInput(A3, 1));
    Boolean x_or_y_2 = Gate_getOutput(A3);

    Circuit_connect(circuit, x_or_y_1, Gate_getInput(A2, 0));
    Boolean x_nor_y_1 = Gate_getOutput(A2);
    Circuit_connect(circuit, x_or_y_2, Gate_getInput(A4, 0));
    Boolean x_nor_y_2 = Gate_getOutput(A4);

    Circuit_connect(circuit, x_nor_y_1, Gate_getInput(A5, 0));
    Circuit_connect(circuit, x_nor_y_2, Gate_getInput(A5, 1));
    Boolean nd_final = Gate_getOutput(A5);

    Circuit_connect(circuit, nd_final, Gate_getInput(A6, 0));
    Boolean final = Gate_getOutput(A6);
    Circuit_connect(circuit, final, result);

    // Done!
    return circuit;
}

static Circuit partC_circuit(void) {
    char *title = "Circuit for Part C";

    // Create the inputs
    int NINPUTS = 3;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean z = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;
    inputs[2] = z;

    // Create the output
    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the gates
    int NGATES = 5;
    Gate A1 = new_OrGate();
    Gate A2 = new_OrGate();
    Gate A3 = new_OrGate();
    Gate A4 = new_AndGate();
    Gate A5 = new_AndGate();
    Gate* gates = new_Gate_array(NGATES);
    gates[0] = A1;
    gates[1] = A2;
    gates[2] = A3;
    gates[3] = A4;
    gates[4] = A5;

    // Create the circuit
    Circuit circuit = new_Circuit(title,
                                  NINPUTS, inputs,
                                  NOUTPUTS, outputs,
                                  NGATES, gates);
    // Connect the gates in the circuit
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A1, 1));
    Boolean x_or_y = Gate_getOutput(A1);
    Circuit_connect(circuit, x, Gate_getInput(A2, 0));
    Circuit_connect(circuit, z, Gate_getInput(A2, 1));
    Boolean x_or_z = Gate_getOutput(A2);
    Circuit_connect(circuit, y, Gate_getInput(A3, 0));
    Circuit_connect(circuit, z, Gate_getInput(A3, 1));
    Boolean y_or_z = Gate_getOutput(A3);

    Circuit_connect(circuit, x_or_y, Gate_getInput(A4, 0));
    Circuit_connect(circuit, x_or_z, Gate_getInput(A4, 1));
    Boolean left_and = Gate_getOutput(A4);
    Circuit_connect(circuit, left_and, Gate_getInput(A5, 0));
    Circuit_connect(circuit, y_or_z, Gate_getInput(A5, 1));
    Boolean final = Gate_getOutput(A5);

    Circuit_connect(circuit, final, result);

    // Done!
    return circuit;
}

static Circuit Extra_circuit(void) {
    char *title = "Circuit for Extra Credit";

    // Create the inputs
    int NINPUTS = 3;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean z = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;
    inputs[2] = z;

    // Create the output
    int NOUTPUTS = 2;
    Boolean result1 = new_Boolean(false);
    Boolean result2 = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result1;
    outputs[1] = result2;

    int NGATES = 10;
    Gate A1 = new_And3Gate();
    Gate A2 = new_And3Gate();
    Gate A3 = new_And3Gate();
    Gate A4 = new_And3Gate();
    Gate A5 = new_And3Gate();

    Gate I1 = new_Inverter();
    Gate I2 = new_Inverter();
    Gate I3 = new_Inverter();

    
    Gate Or1 = new_Or4Gate();
    Gate Or2 = new_Or4Gate();

    Gate* gates = new_Gate_array(NGATES);
    gates[0] = I1;
    gates[1] = I2;
    gates[2] = I3;
    gates[3] = A1;
    gates[4] = A2;
    gates[5] = A3;
    gates[6] = A4;
    gates[7] = A5;
    gates[8] = Or1;
    gates[9] = Or2;

    // Create the circuit
    Circuit circuit = new_Circuit(title,
                                  NINPUTS, inputs,
                                  NOUTPUTS, outputs,
                                  NGATES, gates);

    // Connect the gates in the circuit
    Circuit_connect(circuit, x, Gate_getInput(I1, 0));
    Boolean NotX = Gate_getOutput(I1);
    
    Circuit_connect(circuit, y, Gate_getInput(I2, 0));
    Boolean NotY = Gate_getOutput(I2);

    Circuit_connect(circuit, z, Gate_getInput(I3, 0));
    Boolean NotZ = Gate_getOutput(I3);


    Circuit_connect(circuit, NotX, Gate_getInput(A1, 0));
    Circuit_connect(circuit, NotY, Gate_getInput(A1, 1));
    Circuit_connect(circuit, z, Gate_getInput(A1, 2));
    Boolean NotX_NotY_Z = Gate_getOutput(A1);

    Circuit_connect(circuit, NotX, Gate_getInput(A2, 0));
    Circuit_connect(circuit, y, Gate_getInput(A2, 1));
    Circuit_connect(circuit, NotZ, Gate_getInput(A2, 2));
    Boolean NotX_Y_NotZ = Gate_getOutput(A2);

    Circuit_connect(circuit, NotX, Gate_getInput(A3, 0));
    Circuit_connect(circuit, y, Gate_getInput(A3, 1));
    Circuit_connect(circuit, z, Gate_getInput(A3, 2));
    Boolean NotX_Y_Z = Gate_getOutput(A3);

    Circuit_connect(circuit, x, Gate_getInput(A4, 0));
    Circuit_connect(circuit, y, Gate_getInput(A4, 1));
    Circuit_connect(circuit, z, Gate_getInput(A4, 2));
    Boolean X_Y_Z = Gate_getOutput(A4);

    Circuit_connect(circuit, NotX_NotY_Z, Gate_getInput(Or1, 0));
    Circuit_connect(circuit, NotX_Y_NotZ, Gate_getInput(Or1, 1));
    Circuit_connect(circuit, NotX_Y_Z, Gate_getInput(Or1, 2));
    Circuit_connect(circuit, X_Y_Z, Gate_getInput(Or1, 3));
    Boolean f = Gate_getOutput(Or1);

    Circuit_connect(circuit, x, Gate_getInput(A5, 0));
    Circuit_connect(circuit, NotY, Gate_getInput(A5, 1));
    Circuit_connect(circuit, NotZ, Gate_getInput(A5, 2));
    Boolean X_NotY_NotZ = Gate_getOutput(A5);

    Circuit_connect(circuit, NotX_NotY_Z, Gate_getInput(Or2, 0));
    Circuit_connect(circuit, NotX_Y_NotZ, Gate_getInput(Or2, 1));
    Circuit_connect(circuit, X_NotY_NotZ, Gate_getInput(Or2, 2));
    Circuit_connect(circuit, X_Y_Z, Gate_getInput(Or2, 3));
    Boolean g = Gate_getOutput(Or2);
    
    Circuit_connect(circuit, f, result1);
    Circuit_connect(circuit, g, result2);
    

    // Done!
    return circuit;
}

// You should not use this function in your project.
// It is here to show you how to get and set values in a circuit using the API.
// See the project description for what you are required to do.
// Go to study session if you have questions about how to do it.
static void test3In1Out(Circuit circuit, bool in0, bool in1, bool in2) { // three in one out
    Circuit_setInput(circuit, 0, in0);
    Circuit_setInput(circuit, 1, in1);
    Circuit_setInput(circuit, 2, in2);
    Circuit_update(circuit);
    printf("%s %s %s -> %s\n",
	   Boolean_toString(Circuit_getInput(circuit, 0)),
	   Boolean_toString(Circuit_getInput(circuit, 1)),
	   Boolean_toString(Circuit_getInput(circuit, 2)),
	   Boolean_toString(Circuit_getOutput(circuit, 0)));
}

static void ExtraPrint(Circuit circuit, bool in0, bool in1, bool in2) { // three in one out
    Circuit_setInput(circuit, 0, in0);
    Circuit_setInput(circuit, 1, in1);
    Circuit_setInput(circuit, 2, in2);
    
    Circuit_update(circuit);
    printf("%s %s %s -> %s %s\n",
	   Boolean_toString(Circuit_getInput(circuit, 0)),
	   Boolean_toString(Circuit_getInput(circuit, 1)),
	   Boolean_toString(Circuit_getInput(circuit, 2)),
	   Boolean_toString(Circuit_getOutput(circuit, 0)),
       Boolean_toString(Circuit_getOutput(circuit, 1)));
}

static void test2In1Out(Circuit circuit, bool input1, bool input2) { //two in one out
    Circuit_setInput(circuit, 0, input1);
    Circuit_setInput(circuit, 1, input2);
    Circuit_update(circuit);
    printf("%s %s -> %s\n",
	   Boolean_toString(Circuit_getInput(circuit, 0)),
	   Boolean_toString(Circuit_getInput(circuit, 1)),
	   Boolean_toString(Circuit_getOutput(circuit, 0)));
    //Circuit_dump(circuit);
}

static void TestA(Circuit circuit){
    for (int i =0; i<2; i++){
        bool input1 = (i!=0);
        for (int j = 0; j<2; j++){
            bool input2 = (j != 0);
            test2In1Out(circuit, input1, input2);
        }
    }
}
static void TestB(Circuit circuit){
    for (int i =0; i<2; i++){
        bool input1 = (i!=0);
        for (int j = 0; j<2; j++){
            bool input2 = (j != 0);
            test2In1Out(circuit, input1, input2);
        }
    }
}
static void TestC(Circuit circuit){
    for (int i =0; i<2; i++){
        bool input1 = (i!=0);
        for (int j = 0; j<2; j++){
            bool input2 = (j != 0);
            for (int k =0; k<2; k++){
                bool input3 = (k!=0);
                test3In1Out(circuit, input1, input2, input3);
            }
        }
    }
}
static void TestEx(Circuit circuit){
    for (int i =0; i<2; i++){
        
        bool input1 = (i!=0);
        for (int j = 0; j<2; j++){
            bool input2 = (j != 0);
            for (int k =0; k<2; k++){
                bool input3 = (k!=0);
                ExtraPrint(circuit, input1, input2, input3);
            }
        }
    }
}

int main(int argc, char **argv) {
    
    Circuit A = partA_circuit();
    printf("\n");
    printf("Testing A In Truth Table form\n");
    TestA(A);

    Circuit B = partB_circuit();
    printf("\n");
    printf("Testing B In Truth Table form\n");
    TestB(B);

    Circuit C = partC_circuit();
    printf("\n");
    printf("Testing C In Truth Table form\n");
    TestC(C);
    
    Circuit extra = Extra_circuit();
    //Circuit_dump(extra);
    printf("\n");
    printf("Testing Extra In Truth Table form\n");
    TestEx(extra);

}
