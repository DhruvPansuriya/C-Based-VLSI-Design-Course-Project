; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x72906 (bvmul arg0_16 arg1_8)))
(let ((?x72141 (bvmul (_ bv4294967295 32) ?x72906)))
(let ((?x1054 (bvmul arg0_16 arg1_1)))
(let ((?x70858 (bvadd ?x1054 ?x72141)))
(and (distinct ?x70858 (_ bv0 32)) true))))))
(check-sat)
