; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x725985 (bvmul arg0_10 arg1_11)))
(let ((?x730075 (bvmul (_ bv4294967295 32) ?x725985)))
(let ((?x712216 (bvmul arg0_11 arg1_11)))
(let ((?x728852 (bvadd ?x712216 ?x730075)))
(and (distinct ?x728852 (_ bv0 32)) true))))))
(check-sat)
