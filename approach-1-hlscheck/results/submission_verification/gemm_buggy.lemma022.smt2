; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x205 (bvmul arg0_4 arg1_12)))
(let ((?x21639 (bvmul (_ bv4294967295 32) ?x205)))
(let ((?x229 (bvmul arg0_4 arg1_3)))
(let ((?x11832 (bvadd ?x229 ?x21639)))
(and (distinct ?x11832 (_ bv0 32)) true))))))
(check-sat)
