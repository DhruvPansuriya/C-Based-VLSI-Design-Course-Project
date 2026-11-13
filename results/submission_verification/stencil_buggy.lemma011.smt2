; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_8 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x339256 (bvmul arg0_16 arg2_8)))
(let ((?x714091 (bvmul (_ bv4294967295 32) ?x339256)))
(let ((?x137 (bvmul arg0_16 arg2_7)))
(let ((?x718472 (bvadd ?x137 ?x714091)))
(and (distinct ?x718472 (_ bv0 32)) true))))))
(check-sat)
