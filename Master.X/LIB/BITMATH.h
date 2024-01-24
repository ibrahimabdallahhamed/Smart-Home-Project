/* 
 * File:   BITMATH.h
 * Author: dell
 *
 * Created on October 7, 2023, 11:55 AM
 */

#ifndef BITMATH_H
#define	BITMATH_H

#define  SET_BIT(REG,BIT_NO) (REG |=  (1<<BIT_NO))
#define  CLR_BIT(REG,BIT_NO) (REG &= ~(1<<BIT_NO))
#define  TOG_BIT(REG,BIT_NO) (REG ^=  (1<<BIT_NO))
#define  READ_BIT(REG,BIT_NO)((REG >>BIT_NO) &1)

#endif	/* BITMATH_H */

