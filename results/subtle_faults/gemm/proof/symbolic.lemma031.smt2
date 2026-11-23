; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x187 (bvmul arg0_11 arg1_11)))
(let ((?x19520 (bvmul (_ bv4294967295 32) ?x187)))
(let ((?x109 (bvmul arg0_11 arg1_14)))
(let ((?x16906 (bvadd ?x109 ?x19520)))
(and (distinct ?x16906 (_ bv0 32)) true))))))
(check-sat)
