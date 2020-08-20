CoordinateDescent::CoordinateDescent (
 int nv , // Number of predictor variables
 int nc , // Number of cases we will be training
 int wtd , // Will we be using case weights? 1=Yes, 0=No
 int cu , // Use fast covariance updates rather than slow naive method
 int nl // Number of lambdas we will be using in training
 )


void CoordinateDescent::get_data (
 int istart , // Starting index in full database for getting nc cases of training set
 int n , // Number of cases in full database (we wrap back to the start if needed)
 double *xx , // Full database (n rows, nvars columns)
 double *yy , // Predicted variable vector, n long
 double *ww // Case weights (n long) or NULL if no weighting
 )

 if (w != NULL) {
 sum = 0.0 ;
 for (icase=0 ; icase<ncases ; icase++) {
 k = (icase + istart) % n ; // Wrap to start if needed
 w[icase] = ww[k] ;
 sum += w[icase] ;
 }
 for (icase=0 ; icase<ncases ; icase++)
 w[icase] /= sum ;
 for (ivar=0 ; ivar<nvars ; ivar++) {
 xptr = x + ivar ;
 sum = 0.0 ;
 for (icase=0 ; icase<ncases ; icase++) // Equation 3-13
 sum += w[icase] * xptr[icase*nvars] * xptr[icase*nvars] ;
 XSSvec[ivar] = sum ;
 }
 }


