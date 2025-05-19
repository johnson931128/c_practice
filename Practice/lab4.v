module top(
    input [3:0] SW,
    output [6:0] HEX0
);

    wire [6:0] value;
    multiplier u_multiplier(
        .SW(SW),
        .value(value)
    );
    seven_displye seven(
        .value(value),
        .HEX0(HEX0)
    );
endmodule    





module seven_displyer(
    input [6:0] value,
    output reg [6:0] HEX0
);

always @(*) begin
        case (value)
            7'd0: HEX0 = 7'b1000000;  // 0
            7'd1: HEX0 = 7'b1111001;  // 1
            7'd2: HEX0 = 7'b0100100;  // 2
            7'd3: HEX0 = 7'b0110000;  // 3
            7'd4: HEX0 = 7'b0011001;  // 4
            7'd5: HEX0 = 7'b0010010;  // 5
            7'd6: HEX0 = 7'b0000010;  // 6
            7'd7: HEX0 = 7'b1111000;  // 7
            7'd8: HEX0 = 7'b0000000;  // 8
            7'd9: HEX0 = 7'b0010000;  // 9
            7'd10: HEX0 = 7'b0001000; // A
            7'd11: HEX0 = 7'b0000011; // B
            7'd12: HEX0 = 7'b1000110; // C
            7'd13: HEX0 = 7'b0100001; // D
            7'd14: HEX0 = 7'b0000110; // E
            7'd15: HEX0 = 7'b0001110; // F
            default: HEX0 = 7'b1111111; // 預設關閉顯示
        endcase
    end
endmodule




module multiplier(
    input [3:0] SW,
    output reg [6:0] value
);

    always @(*) begin
        case (SW)
            4'b0000, 4'b0001, 4'b0010 : value = SW;
            4'b0011, 4'b0100, 4'b0101 : value = (SW << 1) + 1;
            4'b0110, 4'b0111, 4'b1000 : value = (SW << 1) - 1;
        endcase
    end
endmodule            