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

for (ivar=0 ; ivar<nvars ; ivar++) {
 xptr = x + ivar ;
 sum = 0.0 ; // Do Yinner
 if (w != NULL) { // Weighted cases
 for (icase=0 ; icase<ncases ; icase++)
 sum += w[icase] * xptr[icase*nvars] * y[icase] ; // Equation 3-14
 Yinner[ivar] = sum ;
 }
 else {
 for (icase=0 ; icase<ncases ; icase++)
 sum += xptr[icase*nvars] * y[icase] ; // Equation 3-11
 Yinner[ivar] = sum / ncases ;
 }
 // Do Xinner
 if (w != NULL) { // Weighted
 for (jvar=0 ; jvar<nvars ; jvar++) {
 if (jvar == ivar)
 Xinner[ivar*nvars+jvar] = XSSvec[ivar] ; // Already computed, so use it
 else if (jvar < ivar) // Matrix is symmetric, so just copy
 Xinner[ivar*nvars+jvar] = Xinner[jvar*nvars+ivar] ;
 else {
 sum = 0.0 ;
 for (icase=0 ; icase<ncases ; icase++)
 sum += w[icase] * xptr[icase*nvars] * x[icase*nvars+jvar] ; // Eq (3-15)
 Xinner[ivar*nvars+jvar] = sum ;
 }
 }
 } // If w
 else { // Unweighted
 for (jvar=0 ; jvar<nvars ; jvar++) {
 if (jvar == ivar)
 Xinner[ivar*nvars+jvar] = 1.0 ; // Recall that X is standardized
 else if (jvar < ivar) // Matrix is symmetric, so just copy
 Xinner[ivar*nvars+jvar] = Xinner[jvar*nvars+ivar] ;


ielse {
 sum = 0.0 ;
 for (icase=0 ; icase<ncases ; icase++)
 sum += xptr[icase*nvars] * x[icase*nvars+jvar] ; // Equation 3-12
 Xinner[ivar*nvars+jvar] = sum / ncases ;
 }
 }
 } // // Else not weighted
 } // For ivar

do_active_only = 0 ; // Begin with a complete pass
 for (iter=0 ; iter<maxits ; iter++) { // Main iteration loop; maxits is for safety only
 active_set_changed = 0 ; // Did any betas go to/from 0.0?
 for (ivar=0 ; ivar<nvars ; ivar++) { // Descend on this beta
 if (do_active_only && beta[ivar] == 0.0)
 continue ;
 [ Compute correction ]
 if (correction != 0.0) { // Did this beta change?
 if ((beta[ivar]==0.0 && new_beta != 0.0) || (beta[ivar] != 0.0 && new_beta==0.0))
 active_set_changed = 1 ;
 }
 } // For all variables; a complete pass
 converged = [ Convergence test ] ;

 if (do_active_only) { // Are we iterating on the active set only?
 if (converged) // If we converged
 do_active_only = 0 ; // We now do a complete pass
 }
 else { // We just did a complete pass (all variables)
 if (converged && ! active_set_changed)
 break ;
 do_active_only = 1 ; // We now do an active-only pass
 }
 } // Outer loop iterations
