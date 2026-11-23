; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x183 (bvmul arg0_11 arg1_3)))
(let ((?x14151 (bvmul (_ bv4294967295 32) ?x183)))
(let ((?x203 (bvmul arg0_11 arg1_12)))
(let ((?x14891 (bvadd ?x203 ?x14151)))
(and (distinct ?x14891 (_ bv0 32)) true))))))
(check-sat)
