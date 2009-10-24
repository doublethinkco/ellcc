# xml_test.mk            see license.txt for copyright and terms of use

.SUFFIX:

# DIFF := diff -u
DIFF := diff -c -b

PR := ./ccparse

.PHONY: all
all: clean
all: check_ast
all: check_type
# all: check_lower

TEST1 :=
TEST1 += t0001.cc
TEST1 += t0002.cc
TEST1 += t0003.cc
TEST1 += t0004.cc
TEST1 += t0005.cc
TEST1 += t0006.cc
TEST1 += t0007.cc
TEST1 += t0008.cc
TEST1 += t0009.cc
TEST1 += t0010.cc
TEST1 += t0011.cc
TEST1 += t0012.cc
TEST1 += t0013.cc
TEST1 += t0014.cc
TEST1 += t0014a.cc
TEST1 += t0015.cc
TEST1 += t0016.cc
TEST1 += t0017.cc
TEST1 += t0018.cc
TEST1 += t0019.cc
TEST1 += t0020.cc
TEST1 += t0021.cc
TEST1 += t0022.cc
TEST1 += t0023.cc
TEST1 += t0024.cc
TEST1 += t0025.cc
TEST1 += t0026.cc
TEST1 += t0027.cc
TEST1 += t0028.cc
TEST1 += t0029.cc
TEST1 += t0030.cc
TEST1 += t0030a.cc
TEST1 += t0030b.cc
TEST1 += t0031.cc
TEST1 += t0032.cc
TEST1 += t0033.cc
TEST1 += t0034.cc
TEST1 += t0035.cc
TEST1 += t0036.cc
TEST1 += t0037.cc
TEST1 += t0038.cc
TEST1 += t0039.cc
TEST1 += t0040.cc
TEST1 += t0041.cc
TEST1 += t0042.cc
TEST1 += t0043.cc
TEST1 += t0044.cc
TEST1 += t0045.cc
TEST1 += t0046.cc
TEST1 += t0047.cc
TEST1 += t0048.cc
TEST1 += t0049.cc
TEST1 += t0050.cc
TEST1 += t0051.cc
TEST1 += t0052.cc
TEST1 += t0053.cc
TEST1 += t0054.cc
TEST1 += t0055.cc
TEST1 += t0056.cc
TEST1 += t0057.cc
TEST1 += t0058.cc
TEST1 += t0059.cc
TEST1 += t0060.cc
TEST1 += t0061.cc
TEST1 += t0062.cc
TEST1 += t0063.cc
TEST1 += t0064.cc
TEST1 += t0065.cc
TEST1 += t0066.cc
TEST1 += t0067.cc
TEST1 += t0068.cc
TEST1 += t0069.cc
TEST1 += t0070.cc
TEST1 += t0071.cc
TEST1 += t0072.cc
TEST1 += t0073.cc
TEST1 += t0074.cc
TEST1 += t0075.cc
TEST1 += t0076.cc
TEST1 += t0077.cc
TEST1 += t0078.cc
TEST1 += t0079.cc
TEST1 += t0080.cc
TEST1 += t0081.cc
TEST1 += t0082.cc
TEST1 += t0083.cc
TEST1 += t0084.cc
TEST1 += t0085.cc
TEST1 += t0086.cc
TEST1 += t0087.cc
TEST1 += t0088.cc
TEST1 += t0089.cc
TEST1 += t0090.cc
TEST1 += t0091.cc
TEST1 += t0092.cc
TEST1 += t0093.cc
TEST1 += t0094.cc
TEST1 += t0095.cc
TEST1 += t0096.cc
TEST1 += t0097.cc
TEST1 += t0098.cc
TEST1 += t0099.cc
TEST1 += t0100.cc

TEST2 :=

TEST2 += t0001.cc
TEST2 += t0002.cc
TEST2 += t0003.cc
TEST2 += t0004.cc
TEST2 += t0005.cc
TEST2 += t0006.cc
TEST2 += t0007.cc
TEST2 += t0008.cc
TEST2 += t0009.cc
TEST2 += t0010.cc
TEST2 += t0011.cc
TEST2 += t0012.cc
TEST2 += t0013.cc
TEST2 += t0014.cc
TEST2 += t0014a.cc
TEST2 += t0015.cc
TEST2 += t0016.cc
TEST2 += t0017.cc
TEST2 += t0018.cc
TEST2 += t0019.cc
TEST2 += t0020.cc
TEST2 += t0021.cc
TEST2 += t0022.cc
TEST2 += t0023.cc
TEST2 += t0024.cc
TEST2 += t0025.cc
TEST2 += t0026.cc
TEST2 += t0027.cc
TEST2 += t0028.cc
TEST2 += t0029.cc
TEST2 += t0030.cc
TEST2 += t0030a.cc
TEST2 += t0030b.cc
TEST2 += t0031.cc
TEST2 += t0032.cc
TEST2 += t0033.cc
TEST2 += t0034.cc
TEST2 += t0035.cc
TEST2 += t0036.cc
TEST2 += t0037.cc
TEST2 += t0038.cc
TEST2 += t0039.cc
TEST2 += t0040.cc
TEST2 += t0041.cc
TEST2 += t0042.cc
TEST2 += t0043.cc
TEST2 += t0044.cc
TEST2 += t0045.cc
TEST2 += t0046.cc
TEST2 += t0047.cc
TEST2 += t0048.cc
TEST2 += t0049.cc
TEST2 += t0050.cc
TEST2 += t0051.cc
TEST2 += t0052.cc
TEST2 += t0053.cc
TEST2 += t0054.cc
TEST2 += t0055.cc
TEST2 += t0056.cc
TEST2 += t0057.cc
TEST2 += t0058.cc
TEST2 += t0059.cc
TEST2 += t0060.cc
TEST2 += t0061.cc
TEST2 += t0062.cc
TEST2 += t0063.cc
TEST2 += t0064.cc
TEST2 += t0065.cc
TEST2 += t0066.cc
TEST2 += t0067.cc
TEST2 += t0068.cc
TEST2 += t0069.cc
TEST2 += t0070.cc
TEST2 += t0071.cc
TEST2 += t0072.cc
TEST2 += t0073.cc
TEST2 += t0074.cc
TEST2 += t0075.cc
TEST2 += t0076.cc
TEST2 += t0077.cc
TEST2 += t0078.cc
TEST2 += t0079.cc
TEST2 += t0080.cc
TEST2 += t0081.cc
TEST2 += t0082.cc
TEST2 += t0083.cc
TEST2 += t0084.cc
TEST2 += t0085.cc
TEST2 += t0086.cc
TEST2 += t0087.cc
TEST2 += t0088.cc
TEST2 += t0089.cc
TEST2 += t0090.cc
TEST2 += t0091.cc
TEST2 += t0092.cc
TEST2 += t0093.cc
TEST2 += t0094.cc
TEST2 += t0095.cc
TEST2 += t0096.cc
TEST2 += t0097.cc
TEST2 += t0098.cc
TEST2 += t0099.cc
TEST2 += t0100.cc
TEST2 += t0101.cc
TEST2 += t0102.cc
TEST2 += t0103.cc
TEST2 += t0104.cc
TEST2 += t0105.cc
TEST2 += t0106.cc
TEST2 += t0107.cc
TEST2 += t0108.cc
TEST2 += t0108b.cc
TEST2 += t0109.cc
TEST2 += t0110.cc
TEST2 += t0111.cc
TEST2 += t0112.cc
TEST2 += t0113.cc
TEST2 += t0114.cc
TEST2 += t0115.cc
TEST2 += t0116.cc
TEST2 += t0117.cc
TEST2 += t0118.cc
TEST2 += t0119.cc
TEST2 += t0120.cc
TEST2 += t0121.cc
TEST2 += t0122.cc
TEST2 += t0123.cc
TEST2 += t0124.cc
TEST2 += t0125.cc
TEST2 += t0126.cc
TEST2 += t0127.cc
TEST2 += t0128.cc
TEST2 += t0129.cc
TEST2 += t0130.cc
TEST2 += t0131.cc
TEST2 += t0132.cc
TEST2 += t0133.cc
TEST2 += t0134.cc
TEST2 += t0135.cc
TEST2 += t0136.cc
TEST2 += t0137.cc
TEST2 += t0138.cc
TEST2 += t0139.cc
TEST2 += t0140.cc
TEST2 += t0141.cc
TEST2 += t0142.cc
TEST2 += t0143.cc
TEST2 += t0144.cc
TEST2 += t0145.cc
TEST2 += t0146.cc
TEST2 += t0147.cc
TEST2 += t0148.cc
TEST2 += t0149.cc
TEST2 += t0150.cc
TEST2 += t0151.cc
TEST2 += t0152.cc
TEST2 += t0153.cc
TEST2 += t0154.cc
TEST2 += t0155.cc
TEST2 += t0156.cc
TEST2 += t0157.cc
TEST2 += t0158.cc
TEST2 += t0159.cc
TEST2 += t0160.cc
TEST2 += t0161.cc
TEST2 += t0162.cc
TEST2 += t0163.cc
TEST2 += t0164.cc
TEST2 += t0165.cc
TEST2 += t0166.cc
TEST2 += t0167.cc
TEST2 += t0168.cc
TEST2 += t0169.cc
TEST2 += t0170.cc
TEST2 += t0171.cc
TEST2 += t0172.cc
TEST2 += t0173.cc
TEST2 += t0174.cc
TEST2 += t0175.cc
TEST2 += t0176.cc
TEST2 += t0177.cc
TEST2 += t0178.cc
TEST2 += t0179.cc
TEST2 += t0180.cc
TEST2 += t0181.cc
TEST2 += t0182.cc
TEST2 += t0183.cc
TEST2 += t0184.cc
TEST2 += t0185.cc
TEST2 += t0186.cc
TEST2 += t0187.cc
TEST2 += t0188.cc
TEST2 += t0189.cc
TEST2 += t0190.cc
TEST2 += t0191.cc
TEST2 += t0192.cc
TEST2 += t0193.cc
TEST2 += t0194.cc
TEST2 += t0195.cc
TEST2 += t0196.cc
TEST2 += t0197.cc
TEST2 += t0198.cc
TEST2 += t0200.cc
TEST2 += t0201.cc
TEST2 += t0202.cc
TEST2 += t0203.cc
TEST2 += t0204.cc
TEST2 += t0205.cc
TEST2 += t0206.cc
TEST2 += t0207.cc
TEST2 += t0208.cc
TEST2 += t0209.cc
TEST2 += t0210.cc
TEST2 += t0211.cc
TEST2 += t0212.cc
TEST2 += t0213.cc
TEST2 += t0214.cc
TEST2 += t0216.cc
TEST2 += t0217.cc
TEST2 += t0218.cc
TEST2 += t0219.cc
TEST2 += t0220.cc
TEST2 += t0221.cc
TEST2 += t0222.cc
TEST2 += t0223.cc
TEST2 += t0224.cc
TEST2 += t0225.cc
TEST2 += t0226.cc
TEST2 += t0227.cc
TEST2 += t0228.cc
TEST2 += t0228b.cc
TEST2 += t0229.cc
TEST2 += t0230.cc
TEST2 += t0231.cc
TEST2 += t0232.cc
TEST2 += t0233.cc
TEST2 += t0234.cc
TEST2 += t0235.cc
TEST2 += t0236.cc
TEST2 += t0237.cc
TEST2 += t0238.cc
TEST2 += t0239.cc
TEST2 += t0240.cc
TEST2 += t0241.cc
TEST2 += t0242.cc
TEST2 += t0243.cc
TEST2 += t0244.cc
TEST2 += t0245.cc
TEST2 += t0246.cc
TEST2 += t0247.cc
TEST2 += t0248.cc
TEST2 += t0249.cc
TEST2 += t0250.cc
TEST2 += t0251.cc
TEST2 += t0252.cc
TEST2 += t0253.cc
TEST2 += t0254.cc
TEST2 += t0255.cc
TEST2 += t0256.cc
TEST2 += t0257.cc
TEST2 += t0258.cc
TEST2 += t0259.cc
TEST2 += t0260.cc
TEST2 += t0261.cc
TEST2 += t0262.cc
TEST2 += t0263.cc
TEST2 += t0264.cc
TEST2 += t0265.cc
TEST2 += t0266.cc
TEST2 += t0268.cc
TEST2 += t0268a.cc
TEST2 += t0269.cc
TEST2 += t0270.cc
TEST2 += t0271.cc
TEST2 += t0272.cc
TEST2 += t0273.cc
TEST2 += t0274.cc
TEST2 += t0275.cc
TEST2 += t0276.cc
TEST2 += t0277.cc
TEST2 += t0278.cc
TEST2 += t0280.cc
TEST2 += t0281.cc
TEST2 += t0282.cc
TEST2 += t0283.cc
TEST2 += t0284.cc
TEST2 += t0285.cc
TEST2 += t0286.cc
TEST2 += t0287.cc
TEST2 += t0288.cc
TEST2 += t0289.cc
TEST2 += t0290.cc
TEST2 += t0290a.cc
TEST2 += t0291.cc
TEST2 += t0292.cc
TEST2 += t0293.cc
TEST2 += t0294.cc
TEST2 += t0295.cc
TEST2 += t0296.cc
TEST2 += t0297.cc
TEST2 += t0298.cc
TEST2 += t0299.cc
TEST2 += t0300.cc
TEST2 += t0301.cc
TEST2 += t0302.cc
TEST2 += t0303.cc
TEST2 += t0304.cc
TEST2 += t0305.cc
TEST2 += t0306.cc
TEST2 += t0307.cc
TEST2 += t0308.cc
TEST2 += t0309.cc
TEST2 += t0310.cc
TEST2 += t0311.cc
TEST2 += t0312.cc
TEST2 += t0313.cc
TEST2 += t0314.cc
TEST2 += t0315.cc
TEST2 += t0316.cc
TEST2 += t0317.cc
TEST2 += t0318.cc
TEST2 += t0319.cc
TEST2 += t0320.cc
TEST2 += t0321.cc
TEST2 += t0322.cc
TEST2 += t0323.cc
TEST2 += t0324.cc
TEST2 += t0325.cc
TEST2 += t0326.cc
TEST2 += t0327.cc
TEST2 += t0328.cc
TEST2 += t0329.cc
TEST2 += t0330.cc
TEST2 += t0331.cc
TEST2 += t0332.cc
TEST2 += t0333.cc
TEST2 += t0334.cc
TEST2 += t0335.cc
TEST2 += t0336.cc
TEST2 += t0337.cc
TEST2 += t0338.cc
TEST2 += t0339.cc
TEST2 += t0340.cc
TEST2 += t0341.cc
TEST2 += t0342.cc
TEST2 += t0343.cc
TEST2 += t0344.cc
TEST2 += t0345.cc
TEST2 += t0346.cc
TEST2 += t0347.cc
TEST2 += t0348.cc
TEST2 += t0349.cc
TEST2 += t0350.cc
TEST2 += t0351.cc
TEST2 += t0352.cc
TEST2 += t0353.cc
TEST2 += t0354.cc
TEST2 += t0355.cc
TEST2 += t0356.cc
TEST2 += t0357.cc
TEST2 += t0358.cc
TEST2 += t0359.cc
TEST2 += t0360.cc
TEST2 += t0361.cc
TEST2 += t0362.cc
TEST2 += t0363.cc
TEST2 += t0364.cc
TEST2 += t0365.cc
TEST2 += t0366.cc
TEST2 += t0367.cc
TEST2 += t0368.cc
TEST2 += t0369.cc
TEST2 += t0370.cc
TEST2 += t0371.cc
TEST2 += t0372.cc
TEST2 += t0373.cc
TEST2 += t0374.cc
TEST2 += t0375.cc
TEST2 += t0376.cc
TEST2 += t0377.cc
TEST2 += t0378.cc
TEST2 += t0379.cc
TEST2 += t0380.cc
TEST2 += t0381.cc
TEST2 += t0382.cc
TEST2 += t0383.cc
TEST2 += t0384.cc
TEST2 += t0385.cc
TEST2 += t0386.cc
TEST2 += t0387.cc
TEST2 += t0388.cc
TEST2 += t0389.cc
TEST2 += t0390.cc
TEST2 += t0391.cc
TEST2 += t0392.cc
TEST2 += t0393.cc
TEST2 += t0394.cc
TEST2 += t0395.cc
TEST2 += t0396.cc
TEST2 += t0397.cc
TEST2 += t0398.cc
TEST2 += t0399.cc
TEST2 += t0400.cc
TEST2 += t0401.cc
TEST2 += t0402.cc
TEST2 += t0403.cc
TEST2 += t0404.cc
TEST2 += t0405.cc
TEST2 += t0406.cc
TEST2 += t0407.cc
TEST2 += t0408.cc
TEST2 += t0409.cc
TEST2 += t0410.cc
TEST2 += t0411.cc
TEST2 += t0412.cc
TEST2 += t0413.cc
TEST2 += t0414.cc
TEST2 += t0415.cc
TEST2 += t0416.cc
TEST2 += t0417.error2.cc
TEST2 += t0418.cc
TEST2 += t0419.cc
TEST2 += t0420.cc
TEST2 += t0421.cc
TEST2 += t0422.cc
TEST2 += t0422a.cc
TEST2 += t0423.cc
TEST2 += t0424.cc
TEST2 += t0425.cc
TEST2 += t0426.cc
TEST2 += t0427.cc
TEST2 += t0428.cc
TEST2 += t0429.cc
TEST2 += t0430.cc
TEST2 += t0431.cc
TEST2 += t0432.cc
TEST2 += t0433.cc
TEST2 += t0434.cc
TEST2 += t0437.cc
TEST2 += t0438.cc
TEST2 += t0438a.cc
TEST2 += t0441.cc
TEST2 += t0441a.cc
TEST2 += t0442.cc
TEST2 += t0443.cc
TEST2 += t0444.cc
TEST2 += t0445.cc
TEST2 += t0446.cc
TEST2 += t0447.cc
TEST2 += t0448.cc
TEST2 += t0449.cc
TEST2 += t0450.cc
TEST2 += t0451.cc
TEST2 += t0452.cc
TEST2 += t0453.cc
TEST2 += t0454.cc
TEST2 += t0455.cc
TEST2 += t0456.cc
TEST2 += t0457.cc
TEST2 += t0458.cc
TEST2 += t0459.cc
TEST2 += t0460.cc
TEST2 += t0461.cc
TEST2 += t0462.cc
TEST2 += t0463.cc
TEST2 += t0467.cc
TEST2 += t0468.cc
TEST2 += t0469.cc
TEST2 += t0470.cc
TEST2 += t0471.cc
TEST2 += t0472.error1.cc
TEST2 += t0473.cc
TEST2 += t0474.cc
TEST2 += t0475.cc
TEST2 += t0476.cc
TEST2 += t0477.cc
TEST2 += t0478.cc
TEST2 += t0479.cc
TEST2 += t0480.cc
TEST2 += t0481.cc
TEST2 += t0482.cc
TEST2 += t0483.cc
TEST2 += t0484.cc
TEST2 += t0485.cc
TEST2 += t0486.cc
TEST2 += t0487.cc
TEST2 += t0487b.cc
TEST2 += t0488.cc
TEST2 += t0489.cc
TEST2 += t0490.cc
TEST2 += t0491.cc
TEST2 += t0492.cc
TEST2 += t0493.cc
TEST2 += t0494.cc
TEST2 += t0495.cc
TEST2 += t0496.cc
TEST2 += t0497.cc
TEST2 += t0498.cc
TEST2 += t0499.cc
TEST2 += t0501.cc
TEST2 += t0502.cc
TEST2 += t0503.cc
TEST2 += t0504.cc
TEST2 += t0505.cc
TEST2 += t0506.cc
TEST2 += t0507.cc
TEST2 += t0508.cc
TEST2 += t0510.cc
TEST2 += t0511.cc
TEST2 += t0512.cc
TEST2 += t0513.cc
TEST2 += t0514.cc
TEST2 += t0515.cc
TEST2 += t0516.cc
TEST2 += t0517.cc
TEST2 += t0522.cc
TEST2 += t0523.cc
TEST2 += t0524.cc
TEST2 += t0525.cc
TEST2 += t0526.cc
TEST2 += t0527.cc
TEST2 += t0528.cc
TEST2 += t0529.cc
TEST2 += t0530.cc
TEST2 += t0531.cc
TEST2 += t0532.cc
TEST2 += t0533.cc
TEST2 += t0534.cc
TEST2 += t0535.cc
TEST2 += t0536.cc
TEST2 += t0537.cc
TEST2 += t0538.cc
TEST2 += t0540.cc
TEST2 += t0541.cc
TEST2 += t0542.cc
TEST2 += t0543.cc
TEST2 += t0544.cc
TEST2 += t0545.cc
TEST2 += t0546.cc
TEST2 += t0547.cc
TEST2 += t0548.cc
TEST2 += t0549.cc
TEST2 += t0550.cc
TEST2 += t0551.cc
TEST2 += t0552.cc
TEST2 += t0553.cc
TEST2 += t0555.cc
TEST2 += t0557.cc
TEST2 += t0558.cc
TEST2 += t0559.cc
TEST2 += t0560.cc
TEST2 += t0561.cc
TEST2 += t0562.cc
TEST2 += t0563.cc
TEST2 += t0564.cc
TEST2 += t0566.cc
TEST2 += t0567.cc
TEST2 += t0568.cc
TEST2 += t0569.cc
TEST2 += d0001.cc
TEST2 += d0002.cc
TEST2 += d0003.cc
TEST2 += d0004.cc
TEST2 += d0005.cc
TEST2 += d0006.cc
TEST2 += d0007.cc
TEST2 += d0008.cc
TEST2 += d0009.cc
TEST2 += d0010.cc
TEST2 += d0011.cc
TEST2 += d0012.cc
TEST2 += d0013.cc
TEST2 += d0014.cc
TEST2 += d0015.cc
TEST2 += d0016.cc
TEST2 += d0017.cc
TEST2 += d0018.cc
TEST2 += d0019.cc
TEST2 += d0020.cc
TEST2 += d0021.cc
TEST2 += d0022.cc
TEST2 += d0023.cc
TEST2 += d0024.cc
TEST2 += d0025.cc
TEST2 += d0026.cc
TEST2 += d0027.cc
TEST2 += d0028.cc
TEST2 += d0029.cc
TEST2 += d0032.cc
TEST2 += d0034.cc
TEST2 += d0035.cc
TEST2 += d0036.cc
TEST2 += d0037.cc
TEST2 += d0038.cc
TEST2 += d0039.cc
TEST2 += d0046.cc
TEST2 += d0046elab.cc
TEST2 += d0047.cc
TEST2 += d0048.cc
TEST2 += d0048elab.cc
TEST2 += d0049.cc
TEST2 += d0050.cc
TEST2 += d0050elab.cc
TEST2 += d0051.cc
TEST2 += d0051elab.cc
TEST2 += d0052.cc
TEST2 += d0053.cc
TEST2 += d0054.cc
TEST2 += d0055.cc
TEST2 += d0056.cc
TEST2 += d0057.cc
TEST2 += d0058.cc
TEST2 += d0059.cc
TEST2 += d0060.cc
TEST2 += d0061.cc
TEST2 += d0064.cc
TEST2 += d0065.cc
TEST2 += d0066.cc
TEST2 += d0067.cc
TEST2 += d0068.cc
TEST2 += d0069.cc
TEST2 += d0070.cc
TEST2 += d0071.cc
TEST2 += d0072.cc
TEST2 += d0073.cc
TEST2 += d0074.cc
TEST2 += d0075.cc
TEST2 += d0079.cc
TEST2 += d0080.cc
TEST2 += d0084.cc
TEST2 += d0088.cc
TEST2 += d0089.cc
TEST2 += d0090.cc
TEST2 += d0091.cc
TEST2 += d0097.cc
TEST2 += d0098.cc
TEST2 += d0099.cc
TEST2 += d0100.cc
TEST2 += d0101.cc
TEST2 += d0102.cc
TEST2 += d0103.cc
TEST2 += d0104.cc
TEST2 += d0105.cc
TEST2 += d0106.cc
TEST2 += d0107.cc
TEST2 += d0108.cc
TEST2 += d0109.cc
TEST2 += d0110.cc
TEST2 += d0111.cc
TEST2 += d0112.cc
TEST2 += d0113.cc
TEST2 += d0114.cc
TEST2 += d0116.cc
TEST2 += d0117.cc
TEST2 += d0118.cc
TEST2 += d0119.cc
TEST2 += d0120.cc
TEST2 += d0124.cc
TEST2 += k0001.cc
TEST2 += k0002.cc
TEST2 += k0003.cc
TEST2 += k0004.cc
TEST2 += k0005.cc
TEST2 += k0005a.cc
TEST2 += k0006.cc
TEST2 += k0007.cc
TEST2 += k0009.cc
TEST2 += k0011.cc
TEST2 += k0012.cc
TEST2 += k0013.cc
TEST2 += k0014.cc
TEST2 += k0015.cc
TEST2 += k0016.cc
TEST2 += k0017.cc
TEST2 += k0018.cc
TEST2 += k0019.cc
TEST2 += k0020.cc
TEST2 += k0021.cc
TEST2 += k0022.cc
TEST2 += k0023.cc
TEST2 += k0024.cc
TEST2 += k0025.cc
TEST2 += k0026.cc
TEST2 += k0027.cc
TEST2 += k0029.cc
TEST2 += k0030.cc
TEST2 += k0031.cc
TEST2 += k0032.cc
TEST2 += k0033.cc
TEST2 += k0035.cc
TEST2 += k0036.cc
TEST2 += k0037.cc
TEST2 += k0038.cc
TEST2 += k0039.cc
TEST2 += k0040.cc
TEST2 += k0041.cc
TEST2 += k0042.cc
TEST2 += k0043.cc
TEST2 += k0045.cc
TEST2 += k0046.cc
TEST2 += k0046a.cc
TEST2 += k0047.cc
TEST2 += k0048.cc
TEST2 += k0049.cc
TEST2 += k0050.cc
TEST2 += k0051.cc
TEST2 += k0052.cc
TEST2 += k0053.cc
TEST2 += k0054.cc
TEST2 += k0055.cc
TEST2 += k0056.cc
TEST2 += k0057.cc
TEST2 += k0058.cc
TEST2 += sg0001.cc

TEST3 :=

# TEST3 += t0001.cc
# TEST3 += t0002.cc
# TEST3 += t0003.cc
# TEST3 += t0004.cc
# TEST3 += t0005.cc
# TEST3 += t0006.cc
# TEST3 += t0007.cc
# TEST3 += t0008.cc
# TEST3 += t0009.cc
# TEST3 += t0010.cc
# TEST3 += t0011.cc
# TEST3 += t0012.cc
# TEST3 += t0013.cc
# TEST3 += t0014.cc
# TEST3 += t0014a.cc
# TEST3 += t0015.cc
# TEST3 += t0016.cc
# TEST3 += t0017.cc
# TEST3 += t0018.cc
# TEST3 += t0019.cc
# TEST3 += t0020.cc
# TEST3 += t0021.cc
# TEST3 += t0022.cc
# TEST3 += t0023.cc
# TEST3 += t0024.cc
# TEST3 += t0025.cc
TEST3 += t0026.cc
TEST3 += t0027.cc
TEST3 += t0028.cc
TEST3 += t0029.cc
TEST3 += t0030.cc
TEST3 += t0030a.cc
TEST3 += t0030b.cc
TEST3 += t0031.cc
TEST3 += t0032.cc
TEST3 += t0033.cc
TEST3 += t0034.cc
TEST3 += t0035.cc
TEST3 += t0036.cc
TEST3 += t0037.cc
TEST3 += t0038.cc
TEST3 += t0039.cc
TEST3 += t0040.cc
TEST3 += t0041.cc
TEST3 += t0042.cc
TEST3 += t0043.cc
TEST3 += t0044.cc
TEST3 += t0045.cc
TEST3 += t0046.cc
TEST3 += t0047.cc
TEST3 += t0048.cc
TEST3 += t0049.cc
TEST3 += t0050.cc
TEST3 += t0051.cc
TEST3 += t0052.cc
TEST3 += t0053.cc
TEST3 += t0054.cc
TEST3 += t0055.cc
TEST3 += t0056.cc
TEST3 += t0057.cc
TEST3 += t0058.cc
TEST3 += t0059.cc
TEST3 += t0060.cc
TEST3 += t0061.cc
TEST3 += t0062.cc
TEST3 += t0063.cc
TEST3 += t0064.cc
TEST3 += t0065.cc
TEST3 += t0066.cc
TEST3 += t0067.cc
TEST3 += t0068.cc
TEST3 += t0069.cc
TEST3 += t0070.cc
TEST3 += t0071.cc
TEST3 += t0072.cc
TEST3 += t0073.cc
TEST3 += t0074.cc
TEST3 += t0075.cc
TEST3 += t0076.cc
TEST3 += t0077.cc
TEST3 += t0078.cc
TEST3 += t0079.cc
TEST3 += t0080.cc
TEST3 += t0081.cc
TEST3 += t0082.cc
TEST3 += t0083.cc
TEST3 += t0084.cc
TEST3 += t0085.cc
TEST3 += t0086.cc
TEST3 += t0087.cc
TEST3 += t0088.cc
TEST3 += t0089.cc
TEST3 += t0090.cc
TEST3 += t0091.cc
TEST3 += t0092.cc
TEST3 += t0093.cc
TEST3 += t0094.cc
TEST3 += t0095.cc
TEST3 += t0096.cc
TEST3 += t0097.cc
TEST3 += t0098.cc
TEST3 += t0099.cc
TEST3 += t0100.cc
TEST3 += t0101.cc
TEST3 += t0102.cc
TEST3 += t0103.cc
TEST3 += t0104.cc
TEST3 += t0105.cc
TEST3 += t0106.cc
TEST3 += t0107.cc
TEST3 += t0108.cc
TEST3 += t0108b.cc
TEST3 += t0109.cc
TEST3 += t0110.cc
TEST3 += t0111.cc
TEST3 += t0112.cc
TEST3 += t0113.cc
TEST3 += t0114.cc
TEST3 += t0115.cc
TEST3 += t0116.cc
TEST3 += t0117.cc
TEST3 += t0118.cc
TEST3 += t0119.cc
TEST3 += t0120.cc
TEST3 += t0121.cc
TEST3 += t0122.cc
TEST3 += t0123.cc
TEST3 += t0124.cc
TEST3 += t0125.cc
TEST3 += t0126.cc
TEST3 += t0127.cc
TEST3 += t0128.cc
TEST3 += t0129.cc
TEST3 += t0130.cc
TEST3 += t0131.cc
TEST3 += t0132.cc
TEST3 += t0133.cc
TEST3 += t0134.cc
TEST3 += t0135.cc
TEST3 += t0136.cc
TEST3 += t0137.cc
TEST3 += t0138.cc
TEST3 += t0139.cc
TEST3 += t0140.cc
TEST3 += t0141.cc
TEST3 += t0142.cc
TEST3 += t0143.cc
TEST3 += t0144.cc
TEST3 += t0145.cc
TEST3 += t0146.cc
TEST3 += t0147.cc
TEST3 += t0148.cc
TEST3 += t0149.cc
TEST3 += t0150.cc
TEST3 += t0151.cc
TEST3 += t0152.cc
TEST3 += t0153.cc
TEST3 += t0154.cc
TEST3 += t0155.cc
TEST3 += t0156.cc
TEST3 += t0157.cc
TEST3 += t0158.cc
TEST3 += t0159.cc
TEST3 += t0160.cc
TEST3 += t0161.cc
TEST3 += t0162.cc
TEST3 += t0163.cc
TEST3 += t0164.cc
TEST3 += t0165.cc
TEST3 += t0166.cc
TEST3 += t0167.cc
TEST3 += t0168.cc
TEST3 += t0169.cc
TEST3 += t0170.cc
TEST3 += t0171.cc
TEST3 += t0172.cc
TEST3 += t0173.cc
TEST3 += t0174.cc
TEST3 += t0175.cc
TEST3 += t0176.cc
TEST3 += t0177.cc
TEST3 += t0178.cc
TEST3 += t0179.cc
TEST3 += t0180.cc
TEST3 += t0181.cc
TEST3 += t0182.cc
TEST3 += t0183.cc
TEST3 += t0184.cc
TEST3 += t0185.cc
TEST3 += t0186.cc
TEST3 += t0187.cc
TEST3 += t0188.cc
TEST3 += t0189.cc
TEST3 += t0190.cc
TEST3 += t0191.cc
TEST3 += t0192.cc
TEST3 += t0193.cc
TEST3 += t0194.cc
TEST3 += t0195.cc
TEST3 += t0196.cc
TEST3 += t0197.cc
TEST3 += t0198.cc
TEST3 += t0200.cc
TEST3 += t0201.cc
TEST3 += t0202.cc
TEST3 += t0203.cc
TEST3 += t0204.cc
TEST3 += t0205.cc
TEST3 += t0206.cc
TEST3 += t0207.cc
TEST3 += t0208.cc
TEST3 += t0209.cc
TEST3 += t0210.cc
TEST3 += t0211.cc
TEST3 += t0212.cc
TEST3 += t0213.cc
TEST3 += t0214.cc
TEST3 += t0216.cc
TEST3 += t0217.cc
TEST3 += t0218.cc
TEST3 += t0219.cc
TEST3 += t0220.cc
TEST3 += t0221.cc
TEST3 += t0222.cc
TEST3 += t0223.cc
TEST3 += t0224.cc
TEST3 += t0225.cc
TEST3 += t0226.cc
TEST3 += t0227.cc
TEST3 += t0228.cc
TEST3 += t0228b.cc
TEST3 += t0229.cc
TEST3 += t0230.cc
TEST3 += t0231.cc
TEST3 += t0232.cc
TEST3 += t0233.cc
TEST3 += t0234.cc
TEST3 += t0235.cc
TEST3 += t0236.cc
TEST3 += t0237.cc
TEST3 += t0238.cc
TEST3 += t0239.cc
TEST3 += t0240.cc
TEST3 += t0241.cc
TEST3 += t0242.cc
TEST3 += t0243.cc
TEST3 += t0244.cc
TEST3 += t0245.cc
TEST3 += t0246.cc
TEST3 += t0247.cc
TEST3 += t0248.cc
TEST3 += t0249.cc
TEST3 += t0250.cc
TEST3 += t0251.cc
TEST3 += t0252.cc
TEST3 += t0253.cc
TEST3 += t0254.cc
TEST3 += t0255.cc
TEST3 += t0256.cc
TEST3 += t0257.cc
TEST3 += t0258.cc
TEST3 += t0259.cc
TEST3 += t0260.cc
TEST3 += t0261.cc
TEST3 += t0262.cc
TEST3 += t0263.cc
TEST3 += t0264.cc
TEST3 += t0265.cc
TEST3 += t0266.cc
TEST3 += t0268.cc
TEST3 += t0268a.cc
TEST3 += t0269.cc
TEST3 += t0270.cc
TEST3 += t0271.cc
TEST3 += t0272.cc
TEST3 += t0273.cc
TEST3 += t0274.cc
TEST3 += t0275.cc
TEST3 += t0276.cc
TEST3 += t0277.cc
TEST3 += t0278.cc
TEST3 += t0280.cc
TEST3 += t0281.cc
TEST3 += t0282.cc
TEST3 += t0283.cc
TEST3 += t0284.cc
TEST3 += t0285.cc
TEST3 += t0286.cc
TEST3 += t0287.cc
TEST3 += t0288.cc
TEST3 += t0289.cc
TEST3 += t0290.cc
TEST3 += t0290a.cc
TEST3 += t0291.cc
TEST3 += t0292.cc
TEST3 += t0293.cc
TEST3 += t0294.cc
TEST3 += t0295.cc
TEST3 += t0296.cc
TEST3 += t0297.cc
TEST3 += t0298.cc
TEST3 += t0299.cc
TEST3 += t0300.cc
TEST3 += t0301.cc
TEST3 += t0302.cc
TEST3 += t0303.cc
TEST3 += t0304.cc
TEST3 += t0305.cc
TEST3 += t0306.cc
TEST3 += t0307.cc
TEST3 += t0308.cc
TEST3 += t0309.cc
TEST3 += t0310.cc
TEST3 += t0311.cc
TEST3 += t0312.cc
TEST3 += t0313.cc
TEST3 += t0314.cc
TEST3 += t0315.cc
TEST3 += t0316.cc
TEST3 += t0317.cc
TEST3 += t0318.cc
TEST3 += t0319.cc
TEST3 += t0320.cc
TEST3 += t0321.cc
TEST3 += t0322.cc
TEST3 += t0323.cc
TEST3 += t0324.cc
TEST3 += t0325.cc
TEST3 += t0326.cc
TEST3 += t0327.cc
TEST3 += t0328.cc
TEST3 += t0329.cc
TEST3 += t0330.cc
TEST3 += t0331.cc
TEST3 += t0332.cc
TEST3 += t0333.cc
TEST3 += t0334.cc
TEST3 += t0335.cc
TEST3 += t0336.cc
TEST3 += t0337.cc
TEST3 += t0338.cc
TEST3 += t0339.cc
TEST3 += t0340.cc
TEST3 += t0341.cc
TEST3 += t0342.cc
TEST3 += t0343.cc
TEST3 += t0344.cc
TEST3 += t0345.cc
TEST3 += t0346.cc
TEST3 += t0347.cc
TEST3 += t0348.cc
TEST3 += t0349.cc
TEST3 += t0350.cc
TEST3 += t0351.cc
TEST3 += t0352.cc
TEST3 += t0353.cc
TEST3 += t0354.cc
TEST3 += t0355.cc
TEST3 += t0356.cc
TEST3 += t0357.cc
TEST3 += t0358.cc
TEST3 += t0359.cc
TEST3 += t0360.cc
TEST3 += t0361.cc
TEST3 += t0362.cc
TEST3 += t0363.cc
TEST3 += t0364.cc
TEST3 += t0365.cc
TEST3 += t0366.cc
TEST3 += t0367.cc
TEST3 += t0368.cc
TEST3 += t0369.cc
TEST3 += t0370.cc
TEST3 += t0371.cc
TEST3 += t0372.cc
TEST3 += t0373.cc
TEST3 += t0374.cc
TEST3 += t0375.cc
TEST3 += t0376.cc
TEST3 += t0377.cc
TEST3 += t0378.cc
TEST3 += t0379.cc
TEST3 += t0380.cc
TEST3 += t0381.cc
TEST3 += t0382.cc
TEST3 += t0383.cc
TEST3 += t0384.cc
TEST3 += t0385.cc
TEST3 += t0386.cc
TEST3 += t0387.cc
TEST3 += t0388.cc
TEST3 += t0389.cc
TEST3 += t0390.cc
TEST3 += t0391.cc
TEST3 += t0392.cc
TEST3 += t0393.cc
TEST3 += t0394.cc
TEST3 += t0395.cc
TEST3 += t0396.cc
TEST3 += t0397.cc
TEST3 += t0398.cc
TEST3 += t0399.cc
TEST3 += t0400.cc
TEST3 += t0401.cc
TEST3 += t0402.cc
TEST3 += t0403.cc
TEST3 += t0404.cc
TEST3 += t0405.cc
TEST3 += t0406.cc
TEST3 += t0407.cc
TEST3 += t0408.cc
TEST3 += t0409.cc
TEST3 += t0410.cc
TEST3 += t0411.cc
TEST3 += t0412.cc
TEST3 += t0413.cc
TEST3 += t0414.cc
TEST3 += t0415.cc
TEST3 += t0416.cc
TEST3 += t0417.error2.cc
TEST3 += t0418.cc
TEST3 += t0419.cc
TEST3 += t0420.cc
TEST3 += t0421.cc
TEST3 += t0422.cc
TEST3 += t0422a.cc
TEST3 += t0423.cc
TEST3 += t0424.cc
TEST3 += t0425.cc
TEST3 += t0426.cc
TEST3 += t0427.cc
TEST3 += t0428.cc
TEST3 += t0429.cc
TEST3 += t0430.cc
TEST3 += t0431.cc
TEST3 += t0432.cc
TEST3 += t0433.cc
TEST3 += t0434.cc
TEST3 += t0437.cc
TEST3 += t0438.cc
TEST3 += t0438a.cc
TEST3 += t0441.cc
TEST3 += t0441a.cc
TEST3 += t0442.cc
TEST3 += t0443.cc
TEST3 += t0444.cc
TEST3 += t0445.cc
TEST3 += t0446.cc
TEST3 += t0447.cc
TEST3 += t0448.cc
TEST3 += t0449.cc
TEST3 += t0450.cc
TEST3 += t0451.cc
TEST3 += t0452.cc
TEST3 += t0453.cc
TEST3 += t0454.cc
TEST3 += t0455.cc
TEST3 += t0456.cc
TEST3 += t0457.cc
TEST3 += t0458.cc
TEST3 += t0459.cc
TEST3 += t0460.cc
TEST3 += t0461.cc
TEST3 += t0462.cc
TEST3 += t0463.cc
TEST3 += t0467.cc
TEST3 += t0468.cc
TEST3 += t0469.cc
TEST3 += t0470.cc
TEST3 += t0471.cc
TEST3 += t0472.error1.cc
TEST3 += t0473.cc
TEST3 += t0474.cc
TEST3 += t0475.cc
TEST3 += t0476.cc
TEST3 += t0477.cc
TEST3 += t0478.cc
TEST3 += t0479.cc
TEST3 += t0480.cc
TEST3 += t0481.cc
TEST3 += t0482.cc
TEST3 += t0483.cc
TEST3 += t0484.cc
TEST3 += t0485.cc
TEST3 += t0486.cc
TEST3 += t0487.cc
TEST3 += t0487b.cc
TEST3 += t0488.cc
TEST3 += t0489.cc
TEST3 += t0490.cc
TEST3 += t0491.cc
TEST3 += t0492.cc
TEST3 += t0493.cc
TEST3 += t0494.cc
TEST3 += t0495.cc
TEST3 += t0496.cc
TEST3 += t0497.cc
TEST3 += t0498.cc
TEST3 += t0499.cc
TEST3 += t0501.cc
TEST3 += t0502.cc
TEST3 += t0503.cc
TEST3 += t0504.cc
TEST3 += t0505.cc
TEST3 += t0506.cc
TEST3 += t0507.cc
TEST3 += t0508.cc
TEST3 += t0510.cc
TEST3 += t0511.cc
TEST3 += t0512.cc
TEST3 += t0513.cc
TEST3 += t0514.cc
TEST3 += t0515.cc
TEST3 += t0516.cc
TEST3 += t0517.cc
TEST3 += t0522.cc
TEST3 += t0523.cc
TEST3 += t0524.cc
TEST3 += t0525.cc
TEST3 += t0526.cc
TEST3 += t0527.cc
TEST3 += t0528.cc
TEST3 += t0529.cc
TEST3 += t0530.cc
TEST3 += t0531.cc
TEST3 += t0532.cc
TEST3 += t0533.cc
TEST3 += t0534.cc
TEST3 += t0535.cc
TEST3 += t0536.cc
TEST3 += t0537.cc
TEST3 += t0538.cc
TEST3 += t0540.cc
TEST3 += t0541.cc
TEST3 += t0542.cc
TEST3 += t0543.cc
TEST3 += t0544.cc
TEST3 += t0545.cc
TEST3 += t0546.cc
TEST3 += t0547.cc
TEST3 += t0548.cc
TEST3 += t0549.cc
TEST3 += t0550.cc
TEST3 += t0551.cc
TEST3 += t0552.cc
TEST3 += t0553.cc
TEST3 += t0555.cc
TEST3 += t0557.cc
TEST3 += t0558.cc
TEST3 += t0559.cc
TEST3 += t0560.cc
TEST3 += t0561.cc
TEST3 += t0562.cc
TEST3 += t0563.cc
TEST3 += t0564.cc
TEST3 += t0566.cc
TEST3 += t0567.cc
TEST3 += t0568.cc
TEST3 += t0569.cc
TEST3 += d0001.cc
TEST3 += d0002.cc
TEST3 += d0003.cc
TEST3 += d0004.cc
TEST3 += d0005.cc
TEST3 += d0006.cc
TEST3 += d0007.cc
TEST3 += d0008.cc
TEST3 += d0009.cc
TEST3 += d0010.cc
TEST3 += d0011.cc
TEST3 += d0012.cc
TEST3 += d0013.cc
TEST3 += d0014.cc
TEST3 += d0015.cc
TEST3 += d0016.cc
TEST3 += d0017.cc
TEST3 += d0018.cc
TEST3 += d0019.cc
TEST3 += d0020.cc
TEST3 += d0021.cc
TEST3 += d0022.cc
TEST3 += d0023.cc
TEST3 += d0024.cc
TEST3 += d0025.cc
TEST3 += d0026.cc
TEST3 += d0027.cc
TEST3 += d0028.cc
TEST3 += d0029.cc
TEST3 += d0032.cc
TEST3 += d0034.cc
TEST3 += d0035.cc
TEST3 += d0036.cc
TEST3 += d0037.cc
TEST3 += d0038.cc
TEST3 += d0039.cc
TEST3 += d0046.cc
TEST3 += d0046elab.cc
TEST3 += d0047.cc
TEST3 += d0048.cc
TEST3 += d0048elab.cc
TEST3 += d0049.cc
TEST3 += d0050.cc
TEST3 += d0050elab.cc
TEST3 += d0051.cc
TEST3 += d0051elab.cc
TEST3 += d0052.cc
TEST3 += d0053.cc
TEST3 += d0054.cc
TEST3 += d0055.cc
TEST3 += d0056.cc
TEST3 += d0057.cc
TEST3 += d0058.cc
TEST3 += d0059.cc
TEST3 += d0060.cc
TEST3 += d0061.cc
TEST3 += d0064.cc
TEST3 += d0065.cc
TEST3 += d0066.cc
TEST3 += d0067.cc
TEST3 += d0068.cc
TEST3 += d0069.cc
TEST3 += d0070.cc
TEST3 += d0071.cc
TEST3 += d0072.cc
TEST3 += d0073.cc
TEST3 += d0074.cc
TEST3 += d0075.cc
TEST3 += d0079.cc
TEST3 += d0080.cc
TEST3 += d0084.cc
TEST3 += d0088.cc
TEST3 += d0089.cc
TEST3 += d0090.cc
TEST3 += d0091.cc
TEST3 += d0097.cc
TEST3 += d0098.cc
TEST3 += d0099.cc
TEST3 += d0100.cc
TEST3 += d0101.cc
TEST3 += d0102.cc
TEST3 += d0103.cc
TEST3 += d0104.cc
TEST3 += d0105.cc
TEST3 += d0106.cc
TEST3 += d0107.cc
TEST3 += d0108.cc
TEST3 += d0109.cc
TEST3 += d0110.cc
TEST3 += d0111.cc
TEST3 += d0112.cc
TEST3 += d0113.cc
TEST3 += d0114.cc
TEST3 += d0116.cc
TEST3 += d0117.cc
TEST3 += d0118.cc
TEST3 += d0119.cc
TEST3 += d0120.cc
TEST3 += d0124.cc
TEST3 += k0001.cc
TEST3 += k0002.cc
TEST3 += k0003.cc
TEST3 += k0004.cc
TEST3 += k0005.cc
TEST3 += k0005a.cc
TEST3 += k0006.cc
TEST3 += k0007.cc
TEST3 += k0009.cc
TEST3 += k0011.cc
TEST3 += k0012.cc
TEST3 += k0013.cc
TEST3 += k0014.cc
TEST3 += k0015.cc
TEST3 += k0016.cc
TEST3 += k0017.cc
TEST3 += k0018.cc
TEST3 += k0019.cc
TEST3 += k0020.cc
TEST3 += k0021.cc
TEST3 += k0022.cc
TEST3 += k0023.cc
TEST3 += k0024.cc
TEST3 += k0025.cc
TEST3 += k0026.cc
TEST3 += k0027.cc
TEST3 += k0029.cc
TEST3 += k0030.cc
TEST3 += k0031.cc
TEST3 += k0032.cc
TEST3 += k0033.cc
TEST3 += k0035.cc
TEST3 += k0036.cc
TEST3 += k0037.cc
TEST3 += k0038.cc
TEST3 += k0039.cc
TEST3 += k0040.cc
TEST3 += k0041.cc
TEST3 += k0042.cc
TEST3 += k0043.cc
TEST3 += k0045.cc
TEST3 += k0046.cc
TEST3 += k0046a.cc
TEST3 += k0047.cc
TEST3 += k0048.cc
TEST3 += k0049.cc
TEST3 += k0050.cc
TEST3 += k0051.cc
TEST3 += k0052.cc
TEST3 += k0053.cc
TEST3 += k0054.cc
TEST3 += k0055.cc
TEST3 += k0056.cc
TEST3 += k0057.cc
TEST3 += k0058.cc
TEST3 += sg0001.cc

TOCLEAN :=

XML_FLAGS :=
# see if the user wants us to indent the XML; default to off because
# it is faster and smaller
ifdef XML_INDENT
XML_FLAGS += -tr xmlPrintAST-indent
endif

# something is not working about serializing source locations that go
# through hashlines
# ifdef XML_HASHLINE
# else
# XML_FLAGS += -tr nohashline
# endif

# **************** section A: there is no section A

# **************** section B: check parsing commutes with xml serialization

T1D := $(addprefix outdir/,$(TEST1))
TOCLEAN += outdir/*.B0.dp outdir/*.B0.dp_filtered outdir/*.B1.xml outdir/*.B1.xml_filtered outdir/*.B2.xml.dp outdir/*.B2.xml.dp_filtered outdir/*.B3.diff

# generate initial debug-print
$(addsuffix .B0.dp,$(T1D)): outdir/%.B0.dp: in/%
	$(PR) -tr no-elaborate,prettyPrint $(XML_FLAGS) $< > $@
$(addsuffix .B0.dp_filtered,$(T1D)): outdir/%.B0.dp_filtered: outdir/%.B0.dp
	./chop_out < $< > $@

# generate xml print
$(addsuffix .B1.xml,$(T1D)): outdir/%.B1.xml: in/%
	$(PR) -tr no-elaborate,xmlPrintAST $(XML_FLAGS) $< > $@
$(addsuffix .B1.xml_filtered,$(T1D)): outdir/%.B1.xml_filtered: outdir/%.B1.xml
	./chop_out < $< > $@

# parse xml and generate second debug-print
$(addsuffix .B2.xml.dp,$(T1D)): outdir/%.B2.xml.dp: outdir/%.B1.xml_filtered
# NOTE: we omit the tracing flag parseXml-no-danglingPointers because
# it will fail on a pure AST de-serialization
	$(PR) -tr parseXml,no-elaborate,prettyPrint $(XML_FLAGS) $< > $@
$(addsuffix .B2.xml.dp_filtered,$(T1D)): outdir/%.B2.xml.dp_filtered: outdir/%.B2.xml.dp
	./chop_out < $< > $@

# diff the two debug-prints
$(addsuffix .B3.diff,$(T1D)): outdir/%.B3.diff: outdir/%.B0.dp_filtered outdir/%.B2.xml.dp_filtered
# NOTE: do not, say, replace this with a pipe into 'tee' because that
# masks the return code and prevents make from stopping if there is a
# difference
	$(DIFF) $^ > $@
# if it passes, delete the temporary files
	rm -f outdir/$*.B?.*

check_ast: $(addsuffix .B3.diff,$(T1D))

# **************** section C: check typechecking commutes with xml serialization

T2D := $(addprefix outdir/,$(TEST2))
TOCLEAN += outdir/*.C0.dp outdir/*.C0.dp_filtered outdir/*.C1.xml outdir/*.C1.xml_filtered outdir/*.C2.xml.dp outdir/*.C2.xml.dp_filtered outdir/*.C3.diff outdir/*.C4.xml

# generate initial debug-print
$(addsuffix .C0.dp,$(T2D)): outdir/%.C0.dp: in/%
	$(PR) -tr no-elaborate,printTypedAST $(XML_FLAGS) $< > $@
$(addsuffix .C0.dp_filtered,$(T2D)): outdir/%.C0.dp_filtered: outdir/%.C0.dp
	./filter_elsa_noise < $< > $@

# generate xml print
$(addsuffix .C1.xml,$(T2D)): outdir/%.C1.xml: in/%
	$(PR) -tr no-elaborate,xmlPrintAST,xmlPrintAST-types $(XML_FLAGS) $< > $@
$(addsuffix .C1.xml_filtered,$(T2D)): outdir/%.C1.xml_filtered: outdir/%.C1.xml
	./chop_out < $< > $@

# parse xml and generate second debug-print
$(addsuffix .C2.xml.dp,$(T2D)): outdir/%.C2.xml.dp: outdir/%.C1.xml_filtered
	$(PR) -tr parseXml,parseXml-no-danglingPointers,no-typecheck,no-elaborate,printAST $(XML_FLAGS) $< > $@
$(addsuffix .C2.xml.dp_filtered,$(T2D)): outdir/%.C2.xml.dp_filtered: outdir/%.C2.xml.dp
	./filter_elsa_noise < $< > $@

# diff the two debug-prints
$(addsuffix .C3.diff,$(T2D)): outdir/%.C3.diff: outdir/%.C0.dp_filtered outdir/%.C2.xml.dp_filtered
# NOTE: do not, say, replace this with a pipe into 'tee' because that
# masks the return code and prevents make from stopping if there is a
# difference
	$(DIFF) $^ > $@
# if it passes, delete the temporary files
	rm -f outdir/$*.C?.*

# # parse xml and generate second xml print
# $(addsuffix .C4.xml,$(T2D)): outdir/%.C4.xml: outdir/%.C1.xml_filtered
# 	$(PR) -tr parseXml,parseXml-no-danglingPointers,no-typecheck,no-elaborate,xmlPrintAST,xmlPrintAST-types $(XML_FLAGS) $< > $@
# $(addsuffix .C4.xml_filtered,$(T2D)): outdir/%.C4.xml_filtered: outdir/%.C4.xml
# 	./chop_out < $< > $@

# # diff the two xml-prints
# $(addsuffix .C5.diff,$(T2D)): outdir/%.C5.diff: outdir/%.C1.xml_filtered outdir/%.C4.xml_filtered
# # NOTE: do not, say, replace this with a pipe into 'tee' because that
# # masks the return code and prevents make from stopping if there is a
# # difference
# 	./filter_ids < $(filter %.C1.xml_filtered,$^) > outdir/a1.xml
# 	./filter_ids < $(filter %.C4.xml_filtered,$^) > outdir/a4.xml
# 	$(DIFF) outdir/a1.xml outdir/a4.xml > $@
# # if it passes, delete the temporary files
# $(error finish this)
# 	rm -f $^ $@

.PHONY: check_type
check_type: $(addsuffix .C3.diff,$(T2D))

# when it works, this test will find things that are being written but
# not read.  Right now, the order of printing is not canonical so it
# is not yet useful.
# check_type: $(addsuffix .C5.diff,$(T2D))

# **************** section D: check lowering commutes with xml serialization

# # NOTE: this is not implemented.
# $(error this is not implemented)

# T3D := $(addprefix outdir/,$(TEST3))
# TOCLEAN += outdir/*.D0.dp outdir/*.D0.dp_filtered outdir/*.D1.xml outdir/*.D1.xml_filtered outdir/*.D2.xml.dp outdir/*.D2.xml.dp_filtered outdir/*.D3.diff outdir/*.D4.xml

# # generate initial debug-print
# $(addsuffix .D0.dp,$(T3D)): outdir/%.D0.dp: in/%
# 	$(PR) -tr prettyPrint $(XML_FLAGS) $< > $@
# $(addsuffix .D0.dp_filtered,$(T3D)): outdir/%.D0.dp_filtered: outdir/%.D0.dp
# 	./chop_out < $< > $@

# # generate xml print
# $(addsuffix .D1.xml,$(T3D)): outdir/%.D1.xml: in/%
# 	$(PR) -tr xmlPrintAST,xmlPrintAST-types,xmlPrintAST-lowered $(XML_FLAGS) $< > $@
# $(addsuffix .D1.xml_filtered,$(T3D)): outdir/%.D1.xml_filtered: outdir/%.D1.xml
# 	./chop_out < $< > $@

# # parse xml and generate second debug-print
# $(addsuffix .D2.xml.dp,$(T3D)): outdir/%.D2.xml.dp: outdir/%.D1.xml_filtered
# 	$(PR) -tr parseXml,parseXml-no-danglingPointers,no-typecheck,no-elaborate,prettyPrint $(XML_FLAGS) $< > $@
# $(addsuffix .D2.xml.dp_filtered,$(T3D)): outdir/%.D2.xml.dp_filtered: outdir/%.D2.xml.dp
# 	./chop_out < $< > $@

# # diff the two debug-prints
# $(addsuffix .D3.diff,$(T3D)): outdir/%.D3.diff: outdir/%.D0.dp_filtered outdir/%.D2.xml.dp_filtered
# # NOTE: do not, say, replace this with a pipe into 'tee' because that
# # masks the return code and prevents make from stopping if there is a
# # difference
# 	$(DIFF) $^ > $@

# .PHONY: check_lower
# check_lower: $(addsuffix .D3.diff,$(T3D))

# ****************

.PHONY: clean
clean:
	find outdir -type f -maxdepth 1 | grep -v .cvsignore | xargs rm -f

# this probably results in an arg too long error
#	rm -f $(TOCLEAN)