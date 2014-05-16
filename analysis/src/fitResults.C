#include "fitResults.h"

Double_t fitResults::a0_HB (Double_t * x, Double_t * par){
  float xx = x[0];
  float erf[4] = {-22.8435060894, 14.5224893267, -0.723468393601, 0.0760768697859};
  float exp[3] = {35.8819933793, -0.665888143699, -6.33697587773};
  float pol11[2] = {-0.0449178885699, -1.073610957e-05};
  float pol12[2] = {0.0279131110041, 8.17056463251e-06};
  float limits[1] = {171.678539393};
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
  float erf[4] = {-14.7961249068, 12.6988892087, -0.574836970044, 0.0422839680797};
  float exp[3] = {17.0269364884, -0.568876191418, -5.80544234621};
  float pol11[2] = {-0.00515102081552, 0.000106369314759};
  float pol12[2] = {0.0421528724576, 1.73530967786e-06};
  float limits[1] = {47.9783049153};
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
  float erf[4] = {-17.6807338184, 13.4331082603, -0.714482578958, 0.0354130818238};
  float exp[3] = {19.1030102404, -0.611870749149, -5.37577876089};
  float pol11[2] = {-0.000401294365651, 0.000120181556225};
  float pol12[2] = {0.0412177744609, 1.27534313824e-06};
  float limits[1] = {52.1929083796};
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
  float erf[4] = {-29.6730709595, 19.1443828945, -0.725818641662, 0.038707031984};
  float exp[3] = {23.064209187, -0.825779711098, -3.22721901687};
  float pol11[2] = {0.000141007746566, 3.80571427844e-05};
  float pol12[2] = {0.042303149177, 1.24480957324e-06};
  float limits[1] = {93.857389278};
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
  float erf[4] = {-25.1100730792, 16.0407685004, -0.907670838242, 0.0626872036856};
  float exp[3] = {25.2531069591, -0.662019682115, -5.14247798673};
  float pol11[2] = {-0.0233999340321, 7.15170213411e-05};
  float pol12[2] = {0.0440438837704, -1.28297424702e-06};
  float limits[1] = {65.3382241833};
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
  float erf[4] = {-22.1710060157, 15.7088200223, -0.745939571917, 0.0225440897333};
  float exp[3] = {11.9685413186, -0.67972623915, -3.79177930073};
  float pol11[2] = {0.0173535064734, 6.17211289936e-05};
  float pol12[2] = {0.044400440393, -4.20967051516e-06};
  float limits[1] = {68.2965695921};
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
  Double_t pol41[5] = {1.96673315288, -0.237636803587, 0.00713777946829, 0.000861663755298, -4.42924714722e-05};
  Double_t pol42[5] = {0.664420980319, 0.00605389136125, -0.00043394022731, 4.19674324461e-06, 4.411805667e-08};
  Double_t pol31[4] = {0.671227356512, -0.002743880327, 1.37452605628e-05, -2.7033570721e-08};
  Double_t pol32[4] = {0.719662628826, -0.00245488277126, 6.63724982429e-06, -5.88243062869e-09};
  Double_t pol11[2] = {0.476195277208, -0.000181568741828};
  Double_t pol12[2] = {0.351262498063, -3.44347768602e-05};
  Double_t limits[5] = {15.0000000172, 35.0000000004, 158.212644182, 300.000000001, 849.109035925};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE1720 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.93045152693, -0.227688154211, 0.0059899383715, 0.000839950331043, -4.03880235508e-05};
  Double_t pol42[5] = {0.878458856797, -0.0225201896273, 0.000562167997098, -3.42668903173e-06, -5.10999689806e-08};
  Double_t pol31[4] = {0.624719042261, -0.00220842695816, 6.36922520014e-06, 1.87600006141e-09};
  Double_t pol32[4] = {0.674340227267, -0.00239376982649, 6.53863131931e-06, -5.7184865452e-09};
  Double_t pol11[2] = {0.426996537602, -0.000120491602127};
  Double_t pol12[2] = {0.269269842986, 0.0};
  Double_t limits[5] = {15.0035267446, 35.0000000003, 150.000000217, 304.987138933, 1309.02645356};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE2123 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.81650074035, -0.204642369685, 0.00538497223796, 0.000731852738287, -3.51708917346e-05};
  Double_t pol42[5] = {0.729384781661, -0.00615391383744, 2.69417905204e-05, 2.60905269392e-07, 5.08697382509e-10};
  Double_t pol31[4] = {0.628954844223, -0.0022373288935, 6.80847006188e-06, -1.57846515612e-09};
  Double_t pol32[4] = {0.453398200581, 0.000739523906529, -7.76241326981e-06, 1.52729714921e-08};
  Double_t pol11[2] = {0.453023380041, -0.00021338323829};
  Double_t pol12[2] = {0.293939078341, 0.0};
  Double_t limits[5] = {15.1906500102, 35.0207218126, 150.000000339, 300.000000025, 745.533262012};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE2425 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.92622913265, -0.228316497443, 0.00611003699613, 0.000844455479063, -4.09403364955e-05};
  Double_t pol42[5] = {0.7872198246, -0.0110981012041, 0.000149705917514, -1.3516305495e-07, -8.58365462575e-09};
  Double_t pol31[4] = {0.632024125002, -0.00234712507591, 9.06579727274e-06, -1.22183707951e-08};
  Double_t pol32[4] = {0.79460252448, -0.00364471298132, 1.08014029283e-05, -1.06226764677e-08};
  Double_t pol11[2] = {0.449453922373, -0.000206518823531};
  Double_t pol12[2] = {0.29156403996, 0.0};
  Double_t limits[5] = {15.0062639093, 41.5000063455, 169.977345537, 305.499927041, 764.530223992};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE2627 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.86263200876, -0.215492960829, 0.00578690564117, 0.000777940906888, -3.78003112796e-05};
  Double_t pol42[5] = {0.671502406093, 0.000932897492512, -0.00023835099168, 2.51899436388e-06, 2.60730471083e-08};
  Double_t pol31[4] = {0.631041201835, -0.0023427672674, 8.63666260694e-06, -9.23985443613e-09};
  Double_t pol32[4] = {0.634175932878, -0.00185890987105, 4.47514578758e-06, -3.53029869623e-09};
  Double_t pol11[2] = {0.443600810322, -0.000184734554872};
  Double_t pol12[2] = {0.293877251748, 0.0};
  Double_t limits[5] = {15.1047246899, 35.5852581123, 153.506391404, 340.499763694, 810.479439957};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE2828 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.89292497507, -0.223572322324, 0.00595740625108, 0.000833426708135, -4.04588958925e-05};
  Double_t pol42[5] = {0.759976751439, -0.00938417704711, 0.000111970039486, 8.12156975068e-08, -7.03380343952e-09};
  Double_t pol31[4] = {0.62568800556, -0.00213759213935, 6.7082275734e-06, -3.50031429081e-09};
  Double_t pol32[4] = {0.804835504892, -0.00402805656399, 1.34445382865e-05, -1.54918202865e-08};
  Double_t pol11[2] = {0.441069571339, -0.000175604918527};
  Double_t pol12[2] = {0.298895396512, 0.0};
  Double_t limits[5] = {15.0006560185, 42.0919538068, 160.00844346, 324.69789247, 809.625242957};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HB (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.524491263367, -0.0577729786293, 0.00162448785276, 0.000167942297662, -7.90674153135e-06};
  Double_t pol42[5] = {0.274861546215, -0.00889751278507, 0.000238503622212, -1.46755581512e-06, -2.08000536487e-08};
  Double_t pol31[4] = {0.179030284194, -0.000589208127741, 2.69136542913e-06, -5.22268261135e-09};
  Double_t pol32[4] = {0.186432951078, -0.000495922688364, 1.0918860001e-06, -7.22548745874e-10};
  Double_t pol11[2] = {0.133710477079, -5.76446954662e-05};
  Double_t pol12[2] = {0.0934001537699, -9.25034404861e-06};
  Double_t limits[5] = {15.8533879915, 35.0000000132, 157.499863825, 300.0, 832.955130683};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE1720 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.511743590441, -0.0592458908763, 0.00148989686614, 0.000201817635889, -9.33948324802e-06};
  Double_t pol42[5] = {0.227363539514, -0.00588309082555, 0.000125495867642, -5.30639395374e-07, -9.73862274868e-09};
  Double_t pol31[4] = {0.155511469859, -0.000629434396328, 2.77920342816e-06, -4.11927293312e-09};
  Double_t pol32[4] = {0.151951521141, -0.000390836649967, 7.45069842499e-07, -1.07927024082e-10};
  Double_t pol11[2] = {0.106015322787, -2.34738760611e-05};
  Double_t pol12[2] = {0.07087750802, 0.0};
  Double_t limits[5] = {15.5142281877, 38.6075716596, 150.000000011, 302.499677286, 1496.89018874};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE2123 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.496286114663, -0.0580267735477, 0.00183394101565, 0.000163723660453, -8.40599232911e-06};
  Double_t pol42[5] = {0.208020640435, -0.00366314202788, 5.72567324584e-05, -1.08435646805e-07, -3.70087931726e-09};
  Double_t pol31[4] = {0.156565786495, -0.000578671504119, 1.92482960569e-06, -1.17613998751e-09};
  Double_t pol32[4] = {0.13146253439, -0.000104831648398, -5.46659480648e-07, 1.689979052e-09};
  Double_t pol11[2] = {0.109879286915, -4.47872196598e-05};
  Double_t pol12[2] = {0.0755258012491, 0.0};
  Double_t limits[5] = {15.0332318989, 42.4999978943, 150.500087304, 300.000000003, 767.037693486};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE2425 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.515952573751, -0.0608758634895, 0.00161258639927, 0.000210742361734, -1.00514149699e-05};
  Double_t pol42[5] = {0.240463401916, -0.00728575930505, 0.000183408544715, -1.07684186444e-06, -1.57738814691e-08};
  Double_t pol31[4] = {0.161633914955, -0.000727149376629, 3.60977649724e-06, -7.19872383101e-09};
  Double_t pol32[4] = {0.249946503716, -0.00160406850433, 5.68182110142e-06, -6.82628066455e-09};
  Double_t pol11[2] = {0.109400475082, -4.60109469909e-05};
  Double_t pol12[2] = {0.0741730843867, 0.0};
  Double_t limits[5] = {15.0117315594, 35.0000000004, 177.733261496, 324.499761521, 765.630637897};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE2627 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.498848725827, -0.0578095043384, 0.00149135158306, 0.000198652384852, -9.29545883546e-06};
  Double_t pol42[5] = {0.230952949642, -0.00580364152155, 7.92781465992e-05, 2.01314505148e-06, -4.85071798494e-08};
  Double_t pol31[4] = {0.159373256052, -0.000709610011518, 3.43094576674e-06, -6.43920635334e-09};
  Double_t pol32[4] = {0.136675970105, -0.000197094855097, -6.57932558867e-08, 8.64828234726e-10};
  Double_t pol11[2] = {0.107134042255, -4.05153232107e-05};
  Double_t pol12[2] = {0.0747901085066, 0.0};
  Double_t limits[5] = {15.3939407571, 35.0000000765, 153.50051661, 300.078988232, 798.313605453};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE2828 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.490870528551, -0.0575906158795, 0.0020224835803, 0.000118242972004, -6.23615605902e-06};
  Double_t pol42[5] = {0.275076614207, -0.0118413418714, 0.000345446864505, -2.41981377656e-06, -2.83638969562e-08};
  Double_t pol31[4] = {0.156976111298, -0.000656761576656, 3.0487237333e-06, -5.48509874447e-09};
  Double_t pol32[4] = {0.190813905108, -0.000923346484099, 3.09063448247e-06, -3.57312863363e-09};
  Double_t pol11[2] = {0.10754625757, -4.01788912592e-05};
  Double_t pol12[2] = {0.0758568834956, 0.0};
  Double_t limits[5] = {15.0682993175, 35.0000001096, 160.83914954, 300.000000014, 788.707032013};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HB (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.17840355644, -0.0201094954125, 0.00051981292118, 6.82322262231e-05, -3.1556437538e-06};
  Double_t pol42[5] = {0.0950187366892, -0.00330592102258, 9.43155686579e-05, -6.07828105851e-07, -8.25881137347e-09};
  Double_t pol31[4] = {0.0610343894165, -0.000152989650296, 6.27375403486e-07, -1.26467354772e-09};
  Double_t pol32[4] = {0.067375237088, -0.000188175310681, 4.68768472402e-07, -4.38884113978e-10};
  Double_t pol11[2] = {0.0483904992616, -2.37618797979e-05};
  Double_t pol12[2] = {0.0313595323721, -3.33753389864e-06};
  Double_t limits[5] = {15.259586124, 35.0000000081, 161.499862115, 300.000000226, 833.856172115};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE1720 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.164413061342, -0.0191002326814, 0.000523488131827, 5.36343877188e-05, -2.45525506496e-06};
  Double_t pol42[5] = {0.0758767495039, -0.00234282091134, 5.53325095938e-05, -2.75242459715e-07, -4.27847820688e-09};
  Double_t pol31[4] = {0.0498569424458, -0.000239377960712, 1.32063769277e-06, -2.80348104429e-09};
  Double_t pol32[4] = {0.0453250975909, -7.90069360821e-05, -1.24669356038e-08, 4.13001295769e-10};
  Double_t pol11[2] = {0.0335767869353, -6.41586460869e-06};
  Double_t pol12[2] = {0.0239529900224, 0.0};
  Double_t limits[5] = {16.4974504663, 39.5000684684, 170.511149297, 300.000000158, 1499.99999998};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE2123 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.173118277159, -0.0207606560938, 0.000532893129943, 6.92261486232e-05, -3.18133863082e-06};
  Double_t pol42[5] = {0.0861414804757, -0.00336405828896, 9.19299665746e-05, -5.7904369258e-07, -8.13000403125e-09};
  Double_t pol31[4] = {0.0504152351797, -0.000209422696784, 7.58682538858e-07, -6.47536023193e-10};
  Double_t pol32[4] = {0.0427760113129, -6.24261434206e-05, -2.18419722845e-08, 2.86254309041e-10};
  Double_t pol11[2] = {0.033313585474, -1.16124586327e-05};
  Double_t pol12[2] = {0.0241984594675, 0.0};
  Double_t limits[5] = {15.5784264529, 35.0000000063, 150.000000348, 301.357930794, 784.943679436};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE2425 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.172640049056, -0.02035703272, 0.000459580465061, 7.56392319436e-05, -3.39342660689e-06};
  Double_t pol42[5] = {0.076663776688, -0.00219542710597, 5.13324530287e-05, -2.67223254672e-07, -4.04069188768e-09};
  Double_t pol31[4] = {0.0528554002045, -0.000272708037809, 1.39169189059e-06, -2.78538680484e-09};
  Double_t pol32[4] = {0.0720292053613, -0.00043693741131, 1.54131253352e-06, -1.84844059016e-09};
  Double_t pol11[2] = {0.0321464764389, -1.066114468e-05};
  Double_t pol12[2] = {0.0230601141024, 0.0};
  Double_t limits[5] = {15.01044444, 37.500103672, 176.500811656, 358.15347941, 852.287686671};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE2627 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.161824888019, -0.0185955425907, 0.000564269638891, 4.4595033297e-05, -2.11838847401e-06};
  Double_t pol42[5] = {0.0690428758601, -0.00143099865039, 1.94197699985e-05, 3.00987769428e-07, -7.65721531423e-09};
  Double_t pol31[4] = {0.0504390908661, -0.000225263235771, 9.43546863165e-07, -1.36133892031e-09};
  Double_t pol32[4] = {0.0527425646465, -0.000196432644632, 5.53182371406e-07, -5.41560133712e-10};
  Double_t pol11[2] = {0.03236950036, -1.09847260547e-05};
  Double_t pol12[2] = {0.0229116533391, 0.0};
  Double_t limits[5] = {16.8576234563, 38.4999797079, 168.500031094, 410.893014811, 860.99980771};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE2828 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.164591325945, -0.0195483730825, 0.000487778859888, 6.48562446912e-05, -2.94464627915e-06};
  Double_t pol42[5] = {0.081338084926, -0.0032233183492, 9.01992989622e-05, -5.79833909242e-07, -7.67228601704e-09};
  Double_t pol31[4] = {0.0491742298524, -0.000219726268255, 1.00355670037e-06, -1.64866592747e-09};
  Double_t pol32[4] = {0.0593774895625, -0.000302835642997, 1.06118996563e-06, -1.2959225155e-09};
  Double_t pol11[2] = {0.0321834891925, -1.05761501806e-05};
  Double_t pol12[2] = {0.0233202767352, 0.0};
  Double_t limits[5] = {15.1386586234, 35.0000000001, 155.49151784, 305.500022466, 838.037689136};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

