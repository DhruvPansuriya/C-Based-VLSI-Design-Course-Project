; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x370138 (bvmul arg0_6 arg1_10)))
(let ((?x15829 (bvmul (_ bv4294967295 32) ?x370138)))
(let ((?x366149 (bvmul arg0_6 arg1_11)))
(let ((?x418139 (bvadd ?x366149 ?x15829)))
(and (distinct ?x418139 (_ bv0 32)) true))))))
(check-sat)
