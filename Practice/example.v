module simple(a, b, cin, cout, sum);
	input	a, b, cin;
	output	cout, sum;
	if (clk == 'd0)
	begin
		
	end

	assign	{ cout, sum } = a + b + cin;
endmodule