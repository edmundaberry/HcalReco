#include "fitResults.h"

Double_t fitResults::a0_HB (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t vars[7] = {0.0696942687402, 1.18209160144, -0.184207693172, 0.0466789495924, -0.000319441039815, 8.60045072438e-06, 58.7669384433};
  if (xx < vars[6]){
    Double_t expo1 = vars[0] * TMath::Exp(vars[1] + vars[2] * xx);
    Double_t pol1  = vars[3] + vars[4] * xx;
    return expo1 + pol1;
  }
  else {
    Double_t offset_expo = vars[0] * TMath::Exp(vars[1] + vars[2] * vars[6]);
    Double_t offset_pol1 = vars[3] + vars[4] * vars[6];
    Double_t offset = offset_expo + offset_pol1;
    Double_t retval = offset + vars[5] * ( xx - vars[6] );
    return retval;
  }
}

Double_t fitResults::a0_HE1720 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t vars[7] = {0.0682168753428, 1.46394321448, -0.211003520653, 0.0637912330152, -0.000461381785182, 1.07918991405e-06, 49.735776805};
  if (xx < vars[6]){
    Double_t expo1 = vars[0] * TMath::Exp(vars[1] + vars[2] * xx);
    Double_t pol1  = vars[3] + vars[4] * xx;
    return expo1 + pol1;
  }
  else {
    Double_t offset_expo = vars[0] * TMath::Exp(vars[1] + vars[2] * vars[6]);
    Double_t offset_pol1 = vars[3] + vars[4] * vars[6];
    Double_t offset = offset_expo + offset_pol1;
    Double_t retval = offset + vars[5] * ( xx - vars[6] );
    return retval;
  }
}

Double_t fitResults::a0_HE2123 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t vars[7] = {0.100686283977, 1.23383163542, -0.262448875999, 0.0742497120045, -0.00086038975385, 1.88182802674e-17, 38.1478548238};
  if (xx < vars[6]){
    Double_t expo1 = vars[0] * TMath::Exp(vars[1] + vars[2] * xx);
    Double_t pol1  = vars[3] + vars[4] * xx;
    return expo1 + pol1;
  }
  else {
    Double_t offset_expo = vars[0] * TMath::Exp(vars[1] + vars[2] * vars[6]);
    Double_t offset_pol1 = vars[3] + vars[4] * vars[6];
    Double_t offset = offset_expo + offset_pol1;
    Double_t retval = offset + vars[5] * ( xx - vars[6] );
    return retval;
  }
}

Double_t fitResults::a0_HE2425 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t vars[7] = {0.088270719659, 1.30031778397, -0.227008515585, 0.0643780987081, -0.000494072267771, 3.02190816814e-13, 46.1113068564};
  if (xx < vars[6]){
    Double_t expo1 = vars[0] * TMath::Exp(vars[1] + vars[2] * xx);
    Double_t pol1  = vars[3] + vars[4] * xx;
    return expo1 + pol1;
  }
  else {
    Double_t offset_expo = vars[0] * TMath::Exp(vars[1] + vars[2] * vars[6]);
    Double_t offset_pol1 = vars[3] + vars[4] * vars[6];
    Double_t offset = offset_expo + offset_pol1;
    Double_t retval = offset + vars[5] * ( xx - vars[6] );
    return retval;
  }
}

Double_t fitResults::a0_HE2627 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t vars[7] = {0.0875612253997, 1.29131983012, -0.23306131628, 0.0678449349652, -0.000534348879093, 3.83947429405e-14, 44.3719565357};
  if (xx < vars[6]){
    Double_t expo1 = vars[0] * TMath::Exp(vars[1] + vars[2] * xx);
    Double_t pol1  = vars[3] + vars[4] * xx;
    return expo1 + pol1;
  }
  else {
    Double_t offset_expo = vars[0] * TMath::Exp(vars[1] + vars[2] * vars[6]);
    Double_t offset_pol1 = vars[3] + vars[4] * vars[6];
    Double_t offset = offset_expo + offset_pol1;
    Double_t retval = offset + vars[5] * ( xx - vars[6] );
    return retval;
  }
}

Double_t fitResults::a0_HE2828 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t vars[7] = {0.0874478895884, 1.39566688055, -0.253280301771, 0.0752533353433, -0.0007597583349, 5.67967894938e-16, 40.3506168935};
  if (xx < vars[6]){
    Double_t expo1 = vars[0] * TMath::Exp(vars[1] + vars[2] * xx);
    Double_t pol1  = vars[3] + vars[4] * xx;
    return expo1 + pol1;
  }
  else {
    Double_t offset_expo = vars[0] * TMath::Exp(vars[1] + vars[2] * vars[6]);
    Double_t offset_pol1 = vars[3] + vars[4] * vars[6];
    Double_t offset = offset_expo + offset_pol1;
    Double_t retval = offset + vars[5] * ( xx - vars[6] );
    return retval;
  }
}

Double_t fitResults::a1_HB (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.97536865735, -0.297395325783, 0.0253905485244, -0.00077470859496, 2.50473915085e-06};
  Double_t pol42[5] = {0.867422842796, -0.00963670536065, 6.64899949481e-05, 4.82558736488e-07, 2.34303883062e-10};
  Double_t pol31[4] = {0.736544224576, -0.00362074111368, 1.89903811468e-05, -3.99076043863e-08};
  Double_t pol32[4] = {0.49528177196, -0.000254688930254, 1.6588453984e-08, 7.23129227363e-11};
  Double_t pol11[2] = {0.408653060355, -8.6861806344e-05};
  Double_t pol12[2] = {0.348677661786, -3.35169848788e-05};
  Double_t limits[5] = {15.0000052342, 38.468275261, 211.269861863, 806.428142143, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE1720 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.76476211848, -0.199746547512, 0.00691362866795, 0.000537501949622, -2.89864518931e-05};
  Double_t pol42[5] = {0.795909105781, -0.00963658193064, 7.80012644512e-05, 5.3969595376e-07, 7.29598198918e-11};
  Double_t pol31[4] = {0.6665015389, -0.00309066901025, 1.6859240914e-05, -3.69255034628e-08};
  Double_t pol32[4] = {0.437449286022, 2.08412550107e-06, -5.51744413559e-07, 4.6776923219e-10};
  Double_t pol11[2] = {0.387733868827, -8.3631318966e-05};
  Double_t pol12[2] = {0.2937074657, 0.0};
  Double_t limits[5] = {15.001758129, 35.7511770841, 211.492745196, 719.991239282, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE2123 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.75935678328, -0.194121163817, 0.00485881212405, 0.000706652241043, -3.28080756687e-05};
  Double_t pol42[5] = {0.767064323249, -0.0083584724111, 6.0222164217e-05, 4.190069935e-07, -1.03350880879e-11};
  Double_t pol31[4] = {0.633169824544, -0.00219531274063, 8.54475336414e-06, -1.37429003067e-08};
  Double_t pol32[4] = {0.542422566127, -0.000896056686126, 1.65385767135e-06, -1.21790662869e-09};
  Double_t pol11[2] = {0.351389153516, -6.22256891509e-05};
  Double_t pol12[2] = {0.281429026074, 0.0};
  Double_t limits[5] = {15.6162982858, 35.0286901839, 254.274484423, 700.000000151, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE2425 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.76150777333, -0.194749121489, 0.00476861501467, 0.000715992532755, -3.30819907741e-05};
  Double_t pol42[5] = {0.785858474589, -0.0103565714132, 9.25103962807e-05, 6.16104787215e-07, -1.56248391153e-10};
  Double_t pol31[4] = {0.64805977366, -0.0028007156225, 1.36172391485e-05, -2.35997346494e-08};
  Double_t pol32[4] = {0.611179366579, -0.00141780039033, 2.80292998225e-06, -1.98006281129e-09};
  Double_t pol11[2] = {0.348286715684, -5.04192504429e-05};
  Double_t pol12[2] = {0.291600526513, 0.0};
  Double_t limits[5] = {15.1651419522, 38.4999056188, 150.500050762, 700.000000007, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE2627 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.83102696245, -0.213969470948, 0.00554464694967, 0.000809351880729, -3.86822931212e-05};
  Double_t pol42[5] = {0.887605569985, -0.0266262134664, 0.000770303782956, -5.52178224086e-06, -7.2513548556e-08};
  Double_t pol31[4] = {0.608549435172, -0.0016164186513, 7.64916940736e-07, 1.94699385363e-08};
  Double_t pol32[4] = {0.585538509507, -0.00121668199332, 2.26956036651e-06, -1.50903927448e-09};
  Double_t pol11[2] = {0.391542376321, -9.02816481314e-05};
  Double_t pol12[2] = {0.290039031077, 0.0};
  Double_t limits[5] = {15.1783660686, 35.0004048707, 150.0, 700.0, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a1_HE2828 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {1.79080228949, -0.203842400782, 0.00503406225449, 0.00076783699389, -3.59612399136e-05};
  Double_t pol42[5] = {0.749465938255, -0.00903836749288, 7.94676868498e-05, 5.19339884286e-07, -4.02929699644e-10};
  Double_t pol31[4] = {0.62771663949, -0.00260526941847, 1.38082494388e-05, -3.02309921699e-08};
  Double_t pol32[4] = {0.49812923646, -0.000445164689615, 2.38769391466e-07, 4.686997915e-11};
  Double_t pol11[2] = {0.509203810762, -0.000232511021423};
  Double_t pol12[2] = {0.247792472257, 0.0};
  Double_t limits[5] = {15.2071751636, 35.1389689941, 194.499502674, 816.545242345, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HB (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.617078114492, -0.0616112327478, 0.00151365636492, 0.000197676726106, -9.14960077042e-06};
  Double_t pol42[5] = {0.361818046937, -0.0127236828542, 0.000328112427294, -1.97245518904e-06, -2.77178481879e-08};
  Double_t pol31[4] = {0.229465695745, -0.00127401213975, 6.49384606104e-06, -1.32122209124e-08};
  Double_t pol32[4] = {0.152514667975, -0.000150817465361, 1.26461594024e-07, -4.34842415462e-11};
  Double_t pol11[2] = {0.10883920823, -2.29879537459e-05};
  Double_t pol12[2] = {0.092073812251, -8.07605525673e-06};
  Double_t limits[5] = {15.3004346541, 35.0000000006, 209.611971713, 809.497602787, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE1720 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.573173103341, -0.0596198916292, 0.00130450393425, 0.000176427817309, -7.52693379248e-06};
  Double_t pol42[5] = {0.323051932443, -0.014466344788, 0.000406889158277, -2.56841486255e-06, -3.50032696979e-08};
  Double_t pol31[4] = {0.176048896394, -0.000819876083664, 4.58406552722e-06, -1.04303439299e-08};
  Double_t pol32[4] = {0.111558845873, 2.95918377104e-05, -2.15468126507e-07, 1.77467356347e-10};
  Double_t pol11[2] = {0.102435271039, -2.1243167791e-05};
  Double_t pol12[2] = {0.0785516508461, 0.0};
  Double_t limits[5] = {15.4169283163, 35.0000024636, 207.952028788, 700.000007588, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE2123 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.586505432169, -0.0655499625014, 0.00146980327766, 0.000219251294265, -9.78929001079e-06};
  Double_t pol42[5] = {0.230075625425, -0.00414543730086, 3.97446350825e-05, 2.5712660731e-07, -6.0846904348e-11};
  Double_t pol31[4] = {0.170427871077, -0.00083957868187, 4.78071707045e-06, -1.10871489885e-08};
  Double_t pol32[4] = {0.138536321106, -0.000222063273037, 3.89849460667e-07, -2.7673253005e-10};
  Double_t pol11[2] = {0.0906779197304, -1.63984458373e-05};
  Double_t pol12[2] = {0.0722412037008, 0.0};
  Double_t limits[5] = {15.2008931265, 39.4990702074, 179.499600498, 700.000003833, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE2425 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.570527026485, -0.0637323088832, 0.00140763380748, 0.000215296242681, -9.54663334793e-06};
  Double_t pol42[5] = {0.18312694093, -0.000534238082158, -4.95536950744e-06, -5.84681112085e-08, -7.70212459422e-10};
  Double_t pol31[4] = {0.157750483891, -0.000565647251862, 2.57001168605e-06, -4.99565993456e-09};
  Double_t pol32[4] = {0.14508648728, -0.00028148956001, 5.07671231879e-07, -3.32062000205e-10};
  Double_t pol11[2] = {0.0908732851021, -1.54542654686e-05};
  Double_t pol12[2] = {0.0734981078007, 0.0};
  Double_t limits[5] = {15.1772019636, 47.6721810387, 225.204397326, 752.491424967, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE2627 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.565047185869, -0.0642347820164, 0.00152373041491, 0.000213809856791, -9.86530715944e-06};
  Double_t pol42[5] = {0.244292943674, -0.00750945868704, 0.00015093308787, 7.08363738549e-07, -3.81560800267e-08};
  Double_t pol31[4] = {0.149387879104, -0.000373816025857, 1.80584507757e-07, 4.00012777141e-09};
  Double_t pol32[4] = {0.133114031089, -0.000180536549249, 2.31850187869e-07, -1.09961479106e-10};
  Double_t pol11[2] = {0.120664037287, -4.85941779388e-05};
  Double_t pol12[2] = {0.0660297708304, 0.0};
  Double_t limits[5] = {15.1024661503, 38.4999854469, 150.000000839, 838.500590581, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a2_HE2828 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.580987941829, -0.0668964905482, 0.00146950748576, 0.000231596667574, -1.03558774328e-05};
  Double_t pol42[5] = {0.215204420639, -0.00415170301635, 4.36740347214e-05, 2.81171158331e-07, -1.21700278261e-10};
  Double_t pol31[4] = {0.13809578401, -6.56056370492e-05, -3.54624050574e-07, -2.26420144175e-09};
  Double_t pol32[4] = {0.1157837154, -1.6822053915e-05, -2.24743381743e-08, -3.57552614141e-11};
  Double_t pol11[2] = {0.0979346065679, -2.45754418277e-05};
  Double_t pol12[2] = {0.0703045221822, 0.0};
  Double_t limits[5] = {15.405692578, 35.000004858, 150.000524521, 700.000000001, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HB (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.352809846798, -0.0353383616943, 0.000651112917183, 0.000103261081724, -4.18563072357e-06};
  Double_t pol42[5] = {0.201465412099, -0.00984373130723, 0.000257036967246, -1.47075040926e-06, -2.1866393621e-08};
  Double_t pol31[4] = {0.0944723672472, -0.000646017952052, 3.59856012508e-06, -7.84966964925e-09};
  Double_t pol32[4] = {0.0495482798312, -8.59531762529e-06, -9.62839597255e-09, -1.29832974921e-11};
  Double_t pol11[2] = {0.0424672904237, -1.15813194832e-05};
  Double_t pol12[2] = {0.0288207172878, 5.46157006198e-07};
  Double_t limits[5] = {16.3900097282, 35.0000000081, 192.704850866, 700.000190735, 1125.26073728};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE1720 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.355852757058, -0.0363898961445, 0.000574424709828, 0.000103005434161, -3.91778518647e-06};
  Double_t pol42[5] = {0.20528113456, -0.0113196289643, 0.000233132966495, 1.5269370624e-06, -6.87244616821e-08};
  Double_t pol31[4] = {0.059470068742, -7.0018046886e-05, -3.76212702108e-07, -2.39055342368e-09};
  Double_t pol32[4] = {0.0300000000438, -1.18014412933e-13, -1.35744182317e-17, 1.38549583581e-19};
  Double_t pol11[2] = {0.0300000000074, -7.53084738581e-15};
  Double_t pol12[2] = {0.0299999999991, 0.0};
  Double_t limits[5] = {17.0794370982, 35.4999682385, 156.870540749, 700.005009842, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE2123 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.368073746565, -0.0409537386046, 0.000743840116936, 0.000124335199274, -5.04112439013e-06};
  Double_t pol42[5] = {0.138904275155, -0.00436424488858, 4.50326049724e-05, 2.82693031461e-07, -1.86517833771e-10};
  Double_t pol31[4] = {0.0559862530453, -6.55469569703e-05, -3.54239196263e-07, -2.26125350916e-09};
  Double_t pol32[4] = {0.0300000000008, -2.552588798e-15, -2.11735694993e-19, 3.51369803542e-21};
  Double_t pol11[2] = {0.0300000000005, -4.97302397288e-16};
  Double_t pol12[2] = {0.0299999999999, 0.0};
  Double_t limits[5] = {16.2168124903, 35.0000023801, 151.689519746, 700.000190399, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE2425 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.344403997808, -0.0350407710138, 0.000472754887626, 0.000104472224291, -3.85941093832e-06};
  Double_t pol42[5] = {0.127318882373, -0.00369912325469, 3.5424672341e-05, 2.3994394682e-07, 5.58886796372e-11};
  Double_t pol31[4] = {0.0541952778729, -5.98462689959e-05, -3.23257532415e-07, -2.06207361798e-09};
  Double_t pol32[4] = {0.0299999999989, 3.79370957552e-15, 1.07670296904e-19, -4.98870847362e-21};
  Double_t pol11[2] = {0.0299999999994, 7.12323319022e-16};
  Double_t pol12[2] = {0.0300000000001, 0.0};
  Double_t limits[5] = {17.1929421855, 35.0000007226, 153.283571353, 700.000189593, 1100.00038147};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE2627 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.340739753397, -0.0360624258554, 0.000641282357168, 0.000102314291801, -4.15560542679e-06};
  Double_t pol42[5] = {0.116762914378, -0.00322955101237, 3.14082232294e-05, 3.91071647837e-07, -6.62323776072e-09};
  Double_t pol31[4] = {0.0497528079187, -5.13901104911e-05, -2.74082604604e-07, -1.74021299402e-09};
  Double_t pol32[4] = {0.03, 2.91139935395e-19, 3.5324582291e-22, 4.84880202311e-25};
  Double_t pol11[2] = {0.03, -1.67377876292e-18};
  Double_t pol12[2] = {0.03, 0.0};
  Double_t limits[5] = {16.1118135428, 37.498693184, 150.016781907, 700.000190735, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

Double_t fitResults::a3_HE2828 (Double_t * x, Double_t * par){
  Double_t xx = x[0];
  Double_t pol41[5] = {0.35677971982, -0.0383634956654, 0.000616660554685, 0.000113528618804, -4.4033032662e-06};
  Double_t pol42[5] = {0.13417726093, -0.00442697293758, 4.51120152062e-05, 2.98388142523e-07, -1.28722994269e-11};
  Double_t pol31[4] = {0.0494260798861, -5.00342422385e-05, -2.70474694386e-07, -1.72707322711e-09};
  Double_t pol32[4] = {0.03, -2.96503028499e-18, -3.57114255334e-21, -4.74261646348e-24};
  Double_t pol11[2] = {0.03, 9.49560751019e-18};
  Double_t pol12[2] = {0.03, 0.0};
  Double_t limits[5] = {16.7636480891, 35.0000021752, 150.025792059, 700.000190735, 1124.29654691};
  if      (                    xx < limits[0] ) return ( ( pol41[0] * 1 ) + ( pol41[1] * xx ) + ( pol41[2] * xx * xx ) + ( pol41[3] * xx * xx * xx ) + ( pol41[4] * xx * xx * xx * xx ) );
  else if ( limits[0] <= xx && xx < limits[1] ) return ( ( pol42[0] * 1 ) + ( pol42[1] * xx ) + ( pol42[2] * xx * xx ) + ( pol42[3] * xx * xx * xx ) + ( pol42[4] * xx * xx * xx * xx ) );
  else if ( limits[1] <= xx && xx < limits[2] ) return ( ( pol31[0] * 1 ) + ( pol31[1] * xx ) + ( pol31[2] * xx * xx ) + ( pol31[3] * xx * xx * xx ) );
  else if ( limits[2] <= xx && xx < limits[3] ) return ( ( pol32[0] * 1 ) + ( pol32[1] * xx ) + ( pol32[2] * xx * xx ) + ( pol32[3] * xx * xx * xx ) );
  else if ( limits[3] <= xx && xx < limits[4] ) return ( ( pol11[0] * 1 ) + ( pol11[1] * xx ) );
  else                                          return ( ( pol12[0] * 1 ) + ( pol12[1] * xx ) );
}

