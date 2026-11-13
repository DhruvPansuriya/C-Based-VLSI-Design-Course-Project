; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x386072 (bvmul arg0_12 arg1_2)))
(let ((?x483219 (bvmul (_ bv4294967295 32) ?x386072)))
(let ((?x505755 (bvmul arg0_12 arg1_3)))
(let ((?x487109 (bvadd ?x505755 ?x483219)))
(and (distinct ?x487109 (_ bv0 32)) true))))))
(check-sat)
