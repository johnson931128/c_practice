module half_adder_struct(
    input a,
    input b,
    output carry,
    output sum
);

    xor (sum, a, b);
    and (carry, a, b);

endmodule

/*
data_flow
assign sum = a ^ b;
assign carry = a & b;
*/


/*
behavior
always @(*)begin
    sum = a ^ b;
    carry = a & b;
end


Structural Description：直接用邏輯閘（如 and、or 等）或模組實例來建構電路。
Dataflow Description：用 assign 和邏輯運算符號（如 &、^）來描述邏輯功能。
Behavioral Description：用高階的 always 或 initial 區塊來描述電路的行為，適合處理較複雜的邏輯。
*/