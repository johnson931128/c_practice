// full adder

module fulladder(
    input wire a,
    input wire b,
    input wire cin,
    output wire w1,
    output wire w2,
    output wire w3,
    output wire sum,
    output wire c_out
);

xor (w1, a, b);
and (w2, a, b);
xor (sum, w1, cin);
and (w3, a, b);
or (c_out, w3, w2);

endmodule

/*
data flow

assign sum = (a ^ b) ^ cin;
assign c_out = ((a ^ b) & cin) || (a & b);
------------------------------------------------------

behavoir

always @(*) begin

    sum = (a ^ b) ^ cin;
    c_out = ((a ^ b) & cin) || (a & b);
end
*/


