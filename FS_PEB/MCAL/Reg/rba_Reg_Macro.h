/*
 * rba_Reg_Macro.h
 *
 *  Created on: Dec 5, 2019
 *      Author: frank.zhang
 */

#ifndef MCAL_REG_RBA_REG_MACRO_H_
#define MCAL_REG_RBA_REG_MACRO_H_


#define rba_Reg_REGS(mod,reg) ((mod).reg)

/* build name of bit(field) position #define */
#define rba_Reg_POS(mod,bit) (RBA_REG_##mod##_##bit##_POS)

/* build name of bit(field) length #define */
#define rba_Reg_LEN(mod,bit) (RBA_REG_##mod##_##bit##_LEN)

/* build a mask with ones at the bit position(s) of a specified bit(field) */
#define rba_Reg_MSK(mod,bit) ((uint32)(((uint32)(1uLL << (rba_Reg_LEN(mod,bit))) - 1uLL) << (rba_Reg_POS(mod,bit))))


/**
 ***************************************************************************************************
 * rba_Reg_SetBit(mod,reg,bit).
 *
 * Set a bit in a peripheral module register to "1".
 * This macro uses the optimum addressing mode for each peripheral module,
 * e.g. single bit instructions (st.t) if possible.
 *
 * \param mod - peripheral module to work on (e.g. ADC0, CAN...)
 * \param reg - register on this peripheral
 * \param bit - bit to be set
 ***************************************************************************************************
 */

#define rba_Reg_SetBit(mod,reg,bit) rba_Reg_SET_BIT_STD(mod,reg,bit)

/**
 ***************************************************************************************************
 * rba_Reg_ClrBit(mod,reg,bit).
 *
 * Set a bit in a peripheral module register to "0".
 * This macro uses the optimum addressing mode for each peripheral module,
 * e.g. single bit instructions (st.t) if possible.
 *
 * \param mod - peripheral module to work on (e.g. ADC0, CAN...)
 * \param reg - register on this peripheral
 * \param bit - bit to be cleared
 ***************************************************************************************************
 */

#define rba_Reg_ClrBit(mod,reg,bit) rba_Reg_CLR_BIT_STD(mod,reg,bit)

/**
 ***************************************************************************************************
 * rba_Reg_PutBit(mod,reg,bit,val).
 *
 * Set the value of a bit in a peripheral register
 * This macro uses the optimum addressing mode for each peripheral module,
 * e.g. single bit instructions (st.t) if possible.
 *
 * \param mod - peripheral module to work on (e.g. ADC0, CAN...)
 * \param reg - register on this peripheral
 * \param bit - bit to be set
 * \param val - value
 ***************************************************************************************************
 */

#define rba_Reg_PutBit(mod,reg,bit,val) rba_Reg_PUT_BIT_STD(mod,reg,bit,val)

/**
 ***************************************************************************************************
 * rba_reg_GetBit(mod,reg,bit).
 *
 * Read the value of a bit in a peripheral register
 *
 * \param mod - peripheral module to work on (e.g. ADC0, CAN...)
 * \param reg - register on this peripheral
 * \param bit - bit to be read
 * \return value of the bit (0/1)
 ***************************************************************************************************
 */

#define rba_Reg_GetBit(mod,reg,bit)                                   \
            ( (boolean)((rba_Reg_REGS(mod,reg) & rba_Reg_MSK(mod,bit)) != 0uL ) )

/**
 ***************************************************************************************************
 * rba_Reg_SetBitField(mod,reg,bitfield,val).
 *
 * Set a bitfield (or a single bit) in a peripheral module register to a specified value
 *
 * \param mod      - peripheral module to work on (e.g. ADC0, CAN...)
 * \param reg      - register on this peripheral
 * \param bitfield - bit or bitfield to be modified
 * \param val      - desired value for bit(field)
 ***************************************************************************************************
 */
#define rba_Reg_SetBitField(mod, reg, bitfield, val)                                                  \
        ( rba_Reg_REGS(mod,reg) =   ( rba_Reg_REGS(mod,reg) & ~rba_Reg_MSK(mod,bitfield) )             \
                          | ( (((uint32)(val)) << rba_Reg_POS(mod,bitfield)) & rba_Reg_MSK(mod,bitfield) ) )

/**
 ***************************************************************************************************
 * rba_Reg_GetBitField(mod,reg,bit).
 *
 * Read the value of a bit in a peripheral register
 *
 * \param mod      - peripheral module to work on (e.g. ADC0, CAN...)
 * \param reg      - register on this peripheral
 * \param bitfield - bitfield to be read
 * \return value of the bitfiled
 ***************************************************************************************************
 */

#define rba_Reg_GetBitField(mod, reg, bitfield)                                 \
            ((rba_Reg_REGS(mod,reg) & rba_Reg_MSK(mod,bitfield)) >> rba_Reg_POS(mod,bitfield))

/**
 ***************************************************************************************************
 * rba_Reg_Mask(bit).
 *
 * Return a bitmask for the specified bit/bitfield which can be used for logical operations
 *
 * \param bit - bit(field) for which a bitmask should be created
 * \return bitmask, contains "1" at the bit position(s) occupied by the specified bit(field)
 ***************************************************************************************************
 */

#define rba_Reg_Mask(mod,reg,bit) rba_Reg_MSK(mod,bit)

/**
 ***************************************************************************************************
 * rba_Reg_Shift(bit).
 *
 * Return the number of bits a value must be shifted to "fit" into the specified bit(field).
 * A possible use case is to extract a bitfield by ANDing a mask created with Reg_Mask() to the
 * register value and right-shifting the result by Reg_Shift().
 *
 * \param bit - bit(field) for which the shift value is to be determined
 * \return shift count
 ***************************************************************************************************
 */

#define rba_Reg_Shift(mod,reg,bit) rba_Reg_POS(mod,bit)

/*
 ***************************************************************************************************
 * Set a bit in a peripheral register to "1", use standard addressing
 ***************************************************************************************************
 */

#define rba_Reg_SET_BIT_STD(mod, reg, bit)                                     \
            ( rba_Reg_REGS(mod,reg) |= rba_Reg_MSK(mod,bit) )

/*
 ***************************************************************************************************
 * Set a bit in a peripheral register to "0", use standard addressing
 ***************************************************************************************************
 */

#define rba_Reg_CLR_BIT_STD(mod, reg, bit)                                     \
            ( rba_Reg_REGS(mod,reg) &= ~rba_Reg_MSK(mod,bit) )

/*
 ***************************************************************************************************
 * Set a bit in a peripheral register to a given value, use standard addressing
 ***************************************************************************************************
 */

#define rba_Reg_PUT_BIT_STD(mod, reg, bit, val)                                \
            ( rba_Reg_REGS(mod,reg) = ((uint32)(val) != 0uL) ?                              \
                              (rba_Reg_REGS(mod,reg) | rba_Reg_MSK(mod,bit)) :              \
                              (rba_Reg_REGS(mod,reg) & ~rba_Reg_MSK(mod,bit)))


#endif /* MCAL_REG_RBA_REG_MACRO_H_ */
