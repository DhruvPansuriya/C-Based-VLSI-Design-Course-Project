; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_17 () (_ BitVec 32))
(declare-fun arg0_25 () (_ BitVec 32))
(declare-fun arg1_10 () (_ BitVec 32))
(assert
 (let ((?x63211 (bvmul arg0_25 arg1_17)))
(let ((?x66828 (bvmul (_ bv4294967295 32) ?x63211)))
(let ((?x31416 (bvmul arg0_25 arg1_10)))
(let ((?x69075 (bvadd ?x31416 ?x66828)))
(and (distinct ?x69075 (_ bv0 32)) true))))))
(check-sat)
