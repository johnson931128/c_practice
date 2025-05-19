module adder_subtractor (
    input [3:0] a, 
    input [3:0] b, 
    input select, 
    output [3:0] S, 
    output C, 
    output V
);
reg [3:0] b_comp;
wire [4:0] sum;

always @(*) begin // always block only use reg to give value
    if (select == 1'b1)
        begin
            b_comp = ~b + 1;
        end
    else 
        begin
            b_comp = b;
        end
end   

assign sum = a + b_comp;    
assign S = sum [3:0];
assign C = sum [4];
assign V = (a[3] ^ b_comp[3] ^ sum[3] ^ sum[4]); // 溢位

endmodule        
