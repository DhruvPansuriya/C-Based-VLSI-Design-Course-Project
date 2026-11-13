; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x23 (bvmul arg0_1 arg1_1)))
(let ((?x223 (bvmul (_ bv4294967295 32) ?x23)))
(let ((?x17 (bvmul arg0_1 arg1_4)))
(let ((?x221 (bvadd ?x17 ?x223)))
(and (distinct ?x221 (_ bv0 32)) true))))))
(check-sat)
