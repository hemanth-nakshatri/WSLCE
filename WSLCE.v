`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:32:24 05/03/2020 
// Design Name: 
// Module Name:    WSLCE 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
`timescale 1ns/1ps

module WSLCE(
	input clk,
	output[N-1:0] wslce_k);
parameter N = 23;
    
    reg[N-1:0] slce;
	 reg[N-1:0] slce_k;
	 reg[N-1:0] wslce_k;
    integer i, j;
    reg boolean;
    reg [100:0]s, z, x;
    
    integer count0=0, count1=0;
     always@(posedge clk)
     //initial
	  begin
        //k=((32'd13) - 1)>>2;
        //$display("%d",k);
        x=100'd11;          // primitive root value
        //$display("%b",x);
        for(i=0; i<N; i=i+1)
        begin
            boolean = 1'b1;
            z = ((x**i)+1)%N;
            for(j=0; j<(N-1)/2; j=j+1)
            begin
                s = ((x**((2*j)+1))%N);
                if ((s==z) & (boolean == 1'b1))
                begin
                    slce[i]=1'b1;
                    boolean = 1'b0;
                    count1 = count1+1;
                end
                if (boolean == 1'b1)
                begin
                    slce[i]=1'b0;
                end 
            end
				//$display("%b", slce[i]);
        end 
			  slce_k={slce[0],slce[N-1:1]};                          
		     wslce_k = slce ^ slce_k; 
		     //$display("count 1 is %d",count1);
     end
	             
	       
	                
    
endmodule
