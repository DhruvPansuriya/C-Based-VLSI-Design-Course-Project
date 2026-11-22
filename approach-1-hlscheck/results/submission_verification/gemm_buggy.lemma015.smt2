; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x171 (bvmul arg0_7 arg1_3)))
(let ((?x101 (bvmul (_ bv4294967295 32) ?x171)))
(let ((?x149 (bvmul arg0_7 arg1_12)))
(let ((?x19296 (bvadd ?x149 ?x101)))
(and (distinct ?x19296 (_ bv0 32)) true))))))
(check-sat)
