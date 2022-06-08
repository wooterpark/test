/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/



#ifndef E2E_PRV_SM_H
#define E2E_PRV_SM_H

/*
 **********************************************************************************************************************
 E2E STATEMACHINE LOCAL DEFINES
 **********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 Prototypes for private routines for the E2E library
 **********************************************************************************************************************
 */

LOCAL_INLINE boolean E2E_Prv_SMCheckConfigAndState(const E2E_SMConfigType * const Config_pst,
                                                   const E2E_SMCheckStateType * const State_pst);

/**
 ***********************************************************************************************************************
 * E2E_Prv_SMCheckConfigAndState
 *
 * \brief Tests the input parameter E2E_SMConfigType and E2E_SMCheckStateType for correctness
 *
 * Description: Tests the input parameter E2E_SMConfigType and E2E_SMCheckStateType for correctness

 *
 * Restrictions:
 *   -
 *
 * Dependencies:
 *   -
 *
 * Resources:
 *   -
 *
 * \param   E2E_SMConfigType       *Config_pst  pointer to the configuration structure of the state machine
 * \return  boolean                             returns TRUE if the check is ok, otherwise returns FALSE
 *
 ***********************************************************************************************************************
 */

LOCAL_INLINE boolean E2E_Prv_SMCheckConfigAndState(const E2E_SMConfigType * const Config_pst,
                                                   const E2E_SMCheckStateType * const State_pst)
{
    // a valid window size has to be at least 1
    // the state has to be initialized to valid value
    // the window needs to be on valid buffer pointer
    // window index counter must be in valid range
    return ((boolean)((Config_pst->WindowSize > 0U) &&
                      ((uint8)State_pst->SMState <= (uint8)E2E_SM_INVALID) &&
                      (NULL_PTR != State_pst->ProfileStatusWindow) &&
                      (State_pst->WindowTopIndex < Config_pst->WindowSize)));
}

/* E2E_PRV_SM_H */
#endif
