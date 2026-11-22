; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_31 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg1_59 () (_ BitVec 32))
(assert
 (let ((?x75271 (bvmul arg0_7 arg1_31)))
(let ((?x75896 (bvmul (_ bv4294967295 32) ?x75271)))
(let ((?x73120 (bvmul arg0_7 arg1_59)))
(let ((?x15172 (bvadd ?x73120 ?x75896)))
(and (distinct ?x15172 (_ bv0 32)) true))))))
(check-sat)
