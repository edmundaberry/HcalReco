#include "fitResults.h"

Double_t fitResults::a0_HB (Double_t * x, Double_t * par){
  float xx = x[0];
  float erf[4] = {-45.9575180078, 22.1763533398, -1.2043445602, 0.0595948079772};
  float exp[3] = {59.3647747212, -1.1506644381, -2.29149471839};
  float pol11[2] = {-0.0347448802483, 2.6418404885e-05};
  float pol12[2] = {0.027470582873, 8.59996754146e-06};
  float limits[1] = {147.075475448};
  if ( xx < limits[0] ){
    Double_t tmp_exp = exp[0] * TMath::Exp((xx-exp[2])*exp[1]);
    Double_t tmp_pol = pol11[0] + pol11[1] * xx;
    Double_t tmp_erf = 0.0;
    Double_t sqrttwo = TMath::Sqrt(2.0);
    tmp_erf += TMath::Erf((xx - erf[0])/(erf[1] * sqrttwo));
    tmp_erf += 1.0;
    tmp_erf *= (( erf[3] - erf[2] ) / 2.0 );
    tmp_erf += erf[2];
    return tmp_erf + tmp_pol + tmp_exp;
  }
  else {
    Double_t tmp_pol = pol12[0] + pol12[1] * xx;
    return tmp_pol;
  }
}
Double_t fitResults::a0_HE1720 (Double_t * x, Double_t * par){
  float xx = x[0];
  float erf[4] = {-35.1332821987, 18.4942650709, -1.79071137202, 0.089219842041};
  float exp[3] = {78.0927188247, -0.877722460326, -3.95350892864};
  float pol11[2] = {-0.0534717994178, 6.52736035615e-05};
  float pol12[2] = {0.0398222971714, 4.61375994521e-06};
  float limits[1] = {67.1660882202};
  if ( xx < limits[0] ){
    Double_t tmp_exp = exp[0] * TMath::Exp((xx-exp[2])*exp[1]);
    Double_t tmp_pol = pol11[0] + pol11[1] * xx;
    Double_t tmp_erf = 0.0;
    Double_t sqrttwo = TMath::Sqrt(2.0);
    tmp_erf += TMath::Erf((xx - erf[0])/(erf[1] * sqrttwo));
    tmp_erf += 1.0;
    tmp_erf *= (( erf[3] - erf[2] ) / 2.0 );
    tmp_erf += erf[2];
    return tmp_erf + tmp_pol + tmp_exp;
  }
  else {
    Double_t tmp_pol = pol12[0] + pol12[1] * xx;
    return tmp_pol;
  }
}
Double_t fitResults::a0_HE2123 (Double_t * x, Double_t * par){
  float xx = x[0];
  float erf[4] = {-15.6197782165, 12.0870986958, -0.863048336132, 0.0109280285913};
  float exp[3] = {1.00666647971, -0.561792612035, -0.825002575737};
  float pol11[2] = {0.0214952102166, 0.000135981840585};
  float pol12[2] = {0.0402891724012, 1.81060545688e-06};
  float limits[1] = {58.6260828609};
  if ( xx < limits[0] ){
    Double_t tmp_exp = exp[0] * TMath::Exp((xx-exp[2])*exp[1]);
    Double_t tmp_pol = pol11[0] + pol11[1] * xx;
    Double_t tmp_erf = 0.0;
    Double_t sqrttwo = TMath::Sqrt(2.0);
    tmp_erf += TMath::Erf((xx - erf[0])/(erf[1] * sqrttwo));
    tmp_erf += 1.0;
    tmp_erf *= (( erf[3] - erf[2] ) / 2.0 );
    tmp_erf += erf[2];
    return tmp_erf + tmp_pol + tmp_exp;
  }
  else {
    Double_t tmp_pol = pol12[0] + pol12[1] * xx;
    return tmp_pol;
  }
}
Double_t fitResults::a0_HE2425 (Double_t * x, Double_t * par){
  float xx = x[0];
  float erf[4] = {-28.9775003331, 16.050539234, -1.67267459378, 0.126328851738};
  float exp[3] = {36.0951991309, -0.604817638811, -6.62847698189};
  float pol11[2] = {-0.0918130219603, 0.000110380158408};
  float pol12[2] = {0.0410229948422, 1.09604955183e-06};
  float limits[1] = {59.5438483837};
  if ( xx < limits[0] ){
    Double_t tmp_exp = exp[0] * TMath::Exp((xx-exp[2])*exp[1]);
    Double_t tmp_pol = pol11[0] + pol11[1] * xx;
    Double_t tmp_erf = 0.0;
    Double_t sqrttwo = TMath::Sqrt(2.0);
    tmp_erf += TMath::Erf((xx - erf[0])/(erf[1] * sqrttwo));
    tmp_erf += 1.0;
    tmp_erf *= (( erf[3] - erf[2] ) / 2.0 );
    tmp_erf += erf[2];
    return tmp_erf + tmp_pol + tmp_exp;
  }
  else {
    Double_t tmp_pol = pol12[0] + pol12[1] * xx;
    return tmp_pol;
  }
}
Double_t fitResults::a0_HE2627 (Double_t * x, Double_t * par){
  float xx = x[0];
  float erf[4] = {-21.6269836547, 15.7690455467, -0.620991083723, 0.0164409637586};
  float exp[3] = {4.9966575457, -0.74469559328, -1.94792547172};
  float pol11[2] = {0.0230113750393, 5.23634248919e-05};
  float pol12[2] = {0.0437691247313, 1.00524437644e-07};
  float limits[1] = {82.5975196202};
  if ( xx < limits[0] ){
    Double_t tmp_exp = exp[0] * TMath::Exp((xx-exp[2])*exp[1]);
    Double_t tmp_pol = pol11[0] + pol11[1] * xx;
    Double_t tmp_erf = 0.0;
    Double_t sqrttwo = TMath::Sqrt(2.0);
    tmp_erf += TMath::Erf((xx - erf[0])/(erf[1] * sqrttwo));
    tmp_erf += 1.0;
    tmp_erf *= (( erf[3] - erf[2] ) / 2.0 );
    tmp_erf += erf[2];
    return tmp_erf + tmp_pol + tmp_exp;
  }
  else {
    Double_t tmp_pol = pol12[0] + pol12[1] * xx;
    return tmp_pol;
  }
}
Double_t fitResults::a0_HE2828 (Double_t * x, Double_t * par){
  float xx = x[0];
  float erf[4] = {-25.4389491889, 16.5326221145, -0.946421921481, 0.0169983607362};
  float exp[3] = {20.6559812086, -0.796812622797, -3.07465538605};
  float pol11[2] = {0.0226617684158, 5.61410122859e-05};
  float pol12[2] = {0.0437716236268, -7.89039631476e-08};
  float limits[1] = {73.1323692335};
  if ( xx < limits[0] ){
    Double_t tmp_exp = exp[0] * TMath::Exp((xx-exp[2])*exp[1]);
    Double_t tmp_pol = pol11[0] + pol11[1] * xx;
    Double_t tmp_erf = 0.0;
    Double_t sqrttwo = TMath::Sqrt(2.0);
    tmp_erf += TMath::Erf((xx - erf[0])/(erf[1] * sqrttwo));
    tmp_erf += 1.0;
    tmp_erf *= (( erf[3] - erf[2] ) / 2.0 );
    tmp_erf += erf[2];
    return tmp_erf + tmp_pol + tmp_exp;
  }
  else {
    Double_t tmp_pol = pol12[0] + pol12[1] * xx;
    return tmp_pol;
  }
}
Double_t fitResults::a1_HB (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.7718783614, -0.181267191687, 0.00535529821194, 0.000613531047781, -3.12830928956e-05};
  Double_t pol42[5] = {0.891079973149, -0.011230683121, 8.8268783774e-05, 6.08424390711e-07, 1.77584086288e-10};
  Double_t pol31[4] = {0.73957045636, -0.00370068549472, 1.96348381765e-05, -4.15227717575e-08};
  Double_t pol32[4] = {0.493133539988, -0.000240103363739, -1.32696678672e-08, 9.14632939901e-11};
  Double_t pol11[2] = {0.40859224908, -8.65069025227e-05};
  Double_t pol12[2] = {0.348121286879, -3.27213044367e-05};
  Double_t limits[5] = {15.0111263639, 36.0900789856, 211.118466796, 798.080489717, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE1720 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.90447015208, -0.219995380945, 0.00598892222281, 0.000788282959468, -3.81559679585e-05};
  Double_t pol42[5] = {0.849396468103, -0.0134280401276, 0.000132806769908, 8.75630022537e-07, -2.35981935383e-10};
  Double_t pol31[4] = {0.676084071441, -0.00341671674318, 2.02822941368e-05, -4.78779800516e-08};
  Double_t pol32[4] = {0.557808672204, -0.000830912484865, 1.21524477202e-06, -6.4438861775e-10};
  Double_t pol11[2] = {0.324728102114, 0.0};
  Double_t pol12[2] = {0.324728102114, 0.0};
  Double_t limits[5] = {15.0038108846, 35.0001261482, 150.000002011, 899.273993063, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE2123 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.90856127388, -0.226748165542, 0.00617153985875, 0.000834164324169, -4.06373079444e-05};
  Double_t pol42[5] = {0.780759028186, -0.0109848075917, 0.000191624512046, -1.60125370537e-06, 4.88442145697e-09};
  Double_t pol31[4] = {0.629718640699, -0.00161751953394, -6.63567234017e-07, 2.35747176213e-08};
  Double_t pol32[4] = {0.505905372478, -0.000194494390947, -4.83144757801e-07, -1.58710499763e-09};
  Double_t pol11[2] = {-1.93854532829, 0.00208902886991};
  Double_t pol12[2] = {0.359387225521, 0.0};
  Double_t limits[5] = {15.0014665637, 107.111877077, 169.559248964, 712.148273456, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE2425 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.85407073063, -0.210399814351, 0.00516209713167, 0.000762742054319, -3.50641395547e-05};
  Double_t pol42[5] = {0.813684669478, -0.0141812974644, 0.000280069892473, -2.57827710993e-06, 8.59591889185e-09};
  Double_t pol31[4] = {0.525840079385, -0.000244463774828, -8.9872434928e-07, -4.38981740641e-09};
  Double_t pol32[4] = {0.492456878689, -0.000161649315935, -4.1907975611e-07, -1.42522935377e-09};
  Double_t pol11[2] = {-1.64189614427, 0.00181415402751};
  Double_t pol12[2] = {0.353673978044, 0.0};
  Double_t limits[5] = {15.3175076409, 122.007852694, 150.382548131, 712.148273456, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE2627 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.89712009113, -0.216741220755, 0.00340002632966, 0.00108508099878, -4.82173501608e-05};
  Double_t pol42[5] = {0.736721188297, -0.00898063672991, 0.000152713251805, -1.31336929628e-06, 4.20958386576e-09};
  Double_t pol31[4] = {4.77958458442, -0.0156773661911, -5.24866264524e-05, -2.34293463398e-07};
  Double_t pol32[4] = {0.50780178293, -0.000213520565263, -5.67922104767e-07, -1.98694073665e-09};
  Double_t pol11[2] = {-2.50590832538, 0.00260620506949};
  Double_t pol12[2] = {0.360918245243, 0.0};
  Double_t limits[5] = {15.0000041101, 148.691756361, 150.000012753, 712.148273456, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE2828 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.89111041479, -0.224096757775, 0.00616850261817, 0.000770937170228, -3.71599538059e-05};
  Double_t pol42[5] = {0.818236761774, -0.0165020225856, 0.000317581358316, -8.78876008069e-07, -2.56796273048e-08};
  Double_t pol31[4] = {0.61235367287, -0.00214390778945, 9.782597347e-06, -1.90858857808e-08};
  Double_t pol32[4] = {0.402429850625, 0.0, 0.0, 0.0};
  Double_t pol11[2] = {0.458988751698, -8.07984301044e-05};
  Double_t pol12[2] = {0.370110447761, 0.0};
  Double_t limits[5] = {15.0288960988, 44.4999721613, 233.08204022, 700.0, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HB (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.600945327272, -0.0635656829116, 0.00181893559327, 0.000205919026925, -1.02533493843e-05};
  Double_t pol42[5] = {0.27553104938, -0.00343754052094, 2.47726357537e-05, 1.66238835339e-07, -6.14663239322e-11};
  Double_t pol31[4] = {0.230301715427, -0.00131232210262, 6.96979494969e-06, -1.50891207851e-08};
  Double_t pol32[4] = {0.164824261957, -0.000239485469404, 3.27616458142e-07, -1.87586086614e-10};
  Double_t pol11[2] = {0.110952876471, -2.51120090215e-05};
  Double_t pol12[2] = {0.0925424598362, -8.73695505067e-06};
  Double_t limits[5] = {15.364838625, 38.0097774592, 184.864199556, 700.000000001, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE1720 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.535901773808, -0.0630820431491, 0.0018466953835, 0.000205070918514, -1.02772481203e-05};
  Double_t pol42[5] = {0.210910869934, -0.00265221868495, 2.42761373524e-05, 1.28727313412e-07, -3.55393105577e-10};
  Double_t pol31[4] = {0.178197623966, -0.000902698024685, 5.54675782145e-06, -1.37453841314e-08};
  Double_t pol32[4] = {0.127204491203, -8.06316376414e-05, 3.89853029644e-08, -2.41717771281e-13};
  Double_t pol11[2] = {0.086095087257, 0.0};
  Double_t pol12[2] = {0.086095087257, 0.0};
  Double_t limits[5] = {15.0000110862, 35.0498433401, 186.93008226, 894.912430797, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE2123 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.500416785729, -0.0564231052415, 0.00147712426193, 0.000188710044461, -8.94946673764e-06};
  Double_t pol42[5] = {0.199431836708, -0.00267778023072, 4.36718444685e-05, -3.41186913623e-07, 9.6371162531e-10};
  Double_t pol31[4] = {0.124180503846, -3.24055218665e-05, -1.20507311006e-07, -5.94683277933e-10};
  Double_t pol32[4] = {0.123650404091, -3.82320753615e-05, -9.90802503207e-08, -3.37492118962e-10};
  Double_t pol11[2] = {-0.382701635097, 0.00043106774959};
  Double_t pol12[2] = {0.0914730538912, 0.0};
  Double_t limits[5] = {15.4524530485, 118.495621559, 152.937520515, 712.148273456, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE2425 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.503861358224, -0.0583388776963, 0.00147905749649, 0.000201642422325, -9.34366546731e-06};
  Double_t pol42[5] = {0.212266969172, -0.00396887510961, 7.85459698258e-05, -7.17313690348e-07, 2.37261323435e-09};
  Double_t pol31[4] = {0.149727324258, -0.000122297897207, -4.41905468601e-07, -2.12401672755e-09};
  Double_t pol32[4] = {0.123766415264, -3.99166774708e-05, -1.03582143777e-07, -3.52533938633e-10};
  Double_t pol11[2] = {-0.403109964158, 0.000447368914059};
  Double_t pol12[2] = {0.0889960119646, 0.0};
  Double_t limits[5] = {15.3583219388, 126.750346884, 150.041834527, 712.148273456, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE2627 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.500329098464, -0.0592299221999, 0.00151624643797, 0.000209200310344, -9.7894331998e-06};
  Double_t pol42[5] = {0.205452783602, -0.00388244670329, 7.82414249672e-05, -7.24312563336e-07, 2.41527992699e-09};
  Double_t pol31[4] = {0.394903740733, -0.00100743777014, -3.45716153627e-06, -1.58137038883e-08};
  Double_t pol32[4] = {0.12444913328, -4.93294281206e-05, -1.31196306942e-07, -4.58976165445e-10};
  Double_t pol11[2] = {-0.571648658258, 0.000601929098093};
  Double_t pol12[2] = {0.0904735792625, 0.0};
  Double_t limits[5] = {15.2925312296, 141.400019662, 150.027378138, 712.148273456, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE2828 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.497090379149, -0.0585315768416, 0.00144944644584, 0.000208403819954, -9.70325519165e-06};
  Double_t pol42[5] = {0.210513915677, -0.0052749388184, 0.000138160692783, -1.65195304391e-06, 7.03680449844e-09};
  Double_t pol31[4] = {0.114283770819, 0.000738071569999, -1.18484247947e-05, 4.67572536713e-08};
  Double_t pol32[4] = {0.14244359515, -0.000101699053589, -3.01504663689e-07, -1.18713465043e-09};
  Double_t pol11[2] = {-1.61923130283, 0.00155527079429};
  Double_t pol12[2] = {0.0915671641823, 0.0};
  Double_t limits[5] = {15.0365707719, 59.1192965848, 150.305076029, 712.148273456, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HB (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.215656902464, -0.020623009994, 0.000520882675444, 6.40781127882e-05, -2.94070296074e-06};
  Double_t pol42[5] = {0.108235585039, -0.00141849553427, 1.06692475488e-05, 7.39357630784e-08, 3.17286122304e-11};
  Double_t pol31[4] = {0.0911309990427, -0.000558242053024, 2.89373453374e-06, -6.14925811267e-09};
  Double_t pol32[4] = {0.0650495674904, -0.000118296767465, 1.66146348843e-07, -9.29147772914e-11};
  Double_t pol11[2] = {0.0386081658974, -9.74913330179e-06};
  Double_t pol12[2] = {0.0312853173237, -3.23586187551e-06};
  Double_t limits[5] = {16.1004901486, 35.1423965194, 178.795594118, 700.000000067, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE1720 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.185110920411, -0.0220474879985, 0.000583491358061, 7.34224691126e-05, -3.40633289568e-06};
  Double_t pol42[5] = {0.0766540271164, -0.00129962761981, 1.42790451441e-05, 8.66684847181e-08, -5.67168536026e-11};
  Double_t pol31[4] = {0.0602819025406, -0.000283905537523, 1.74834925685e-06, -4.60047190804e-09};
  Double_t pol32[4] = {0.0446889108155, -3.22056694854e-05, 1.71520864499e-08, -6.86054398684e-13};
  Double_t pol11[2] = {0.0291172116264, 0.0};
  Double_t pol12[2] = {0.0291172116264, 0.0};
  Double_t limits[5] = {15.5943355589, 35.0000002959, 173.688105796, 893.435383483, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE2123 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.176201346008, -0.0208107813893, 0.000518429689095, 6.74082902976e-05, -2.97885249873e-06};
  Double_t pol42[5] = {0.0707351752559, -0.00118976268829, 2.11045115795e-05, -1.73010338645e-07, 5.07085022547e-10};
  Double_t pol31[4] = {2.08093907424, -0.00743066898425, -2.47797796066e-05, -1.10180736849e-07};
  Double_t pol32[4] = {0.039773848337, -1.21989073529e-05, -3.18686372361e-08, -1.09265791501e-10};
  Double_t pol11[2] = {-0.123537609822, 0.000139013456638};
  Double_t pol12[2] = {0.029377245509, 0.0};
  Double_t limits[5] = {16.4103593025, 149.867674543, 150.00338989, 712.148273456, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE2425 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.16840490716, -0.0194672811286, 0.000463068158495, 6.46579882642e-05, -2.84799362366e-06};
  Double_t pol42[5] = {0.0647978423472, -0.000904405804159, 1.52026061852e-05, -1.23581578332e-07, 3.64381166423e-10};
  Double_t pol31[4] = {0.0762279871236, -0.000145503055433, -4.92078830986e-07, -2.21873392936e-09};
  Double_t pol32[4] = {0.0382868921961, -1.02621349178e-05, -2.66307183872e-08, -9.06402185199e-11};
  Double_t pol11[2] = {-0.0955125321143, 0.00011268560373};
  Double_t pol12[2] = {0.0284416749751, 0.0};
  Double_t limits[5] = {15.9360132731, 145.69000009, 150.000138685, 712.148273456, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE2627 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.163042789182, -0.0190746486647, 0.000452276581186, 6.23909639447e-05, -2.72075812462e-06};
  Double_t pol42[5] = {0.0634674652438, -0.00107130789828, 2.07518512895e-05, -1.87414696172e-07, 6.03110344015e-10};
  Double_t pol31[4] = {0.126504082609, -0.000326958092698, -1.10586032849e-06, -4.98673141872e-09};
  Double_t pol32[4] = {0.039863369816, -1.7063665306e-05, -4.53851616753e-08, -1.5878352323e-10};
  Double_t pol11[2] = {-0.200932944851, 0.000208214143043};
  Double_t pol12[2] = {0.0281026919242, 0.0};
  Double_t limits[5] = {15.9504947403, 145.658632111, 150.001607336, 712.148273456, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE2828 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.151690858758, -0.0175544860705, 0.000431798232906, 5.8162041793e-05, -2.65181836599e-06};
  Double_t pol42[5] = {0.0542138842015, -0.000498529872313, 2.74703652012e-06, 1.89523554516e-08, -2.49796237559e-11};
  Double_t pol31[4] = {0.0457293107794, -0.000164945182872, 8.38521420393e-07, -1.81603894655e-09};
  Double_t pol32[4] = {0.0289893381443, -2.69310415802e-07, -2.84826804584e-10, -3.72929548739e-13};
  Double_t pol11[2] = {0.0287475325198, -3.05988299496e-07};
  Double_t pol12[2] = {0.0284109452736, 0.0};
  Double_t limits[5] = {15.1900103434, 35.0000011786, 245.523234099, 700.000190735, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

