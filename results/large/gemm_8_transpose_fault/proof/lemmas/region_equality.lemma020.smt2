; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_22 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_50 () (_ BitVec 32))
(assert
 (let ((?x75306 (bvmul arg0_6 arg1_22)))
(let ((?x65719 (bvmul (_ bv4294967295 32) ?x75306)))
(let ((?x63365 (bvmul arg0_6 arg1_50)))
(let ((?x64763 (bvadd ?x63365 ?x65719)))
(and (distinct ?x64763 (_ bv0 32)) true))))))
(check-sat)
