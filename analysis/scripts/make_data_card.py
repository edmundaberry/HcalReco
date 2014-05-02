import subprocess as sp

input_path = "/Users/eberry/Downloads/make_AlexandersCorrections.cc"

functions = [1, 2, 3]
rings = ["HB", "1720", "2123", "2425", "2627", "28" ]

output_path = "data_card.txt"
output_file = open (output_path, "w")

for function in functions:
    for iring, ring in enumerate(rings):
        poly_name = "a" + str(function) + "_" + ring
        command = "cat " + input_path + " | grep \"PiecewiseScalingPolynomial " + poly_name + "\" -A 8"
        output  = sp.Popen ( command, shell=True, stdout=sp.PIPE).communicate()[0]
        lines = output.split("\n")
        iline = 0
        for line in lines:
            line = line.strip()
            if "pol" not in line and "limits" not in line: continue
            region_of_interest = line.split("{")[1].split("}")[0]
            region_of_interest = region_of_interest.replace(","," ")        
            line_to_write = "%d" % function + " %d" % iring
            if "limits" in line:
                line_to_write = line_to_write + " L " + region_of_interest 
            else:
                line_to_write = line_to_write + " %d " % iline + region_of_interest 
            output_file.write(line_to_write + "\n")
            iline += 1

output_file.close()
            
